// ----------------------------------------------------------------------------
// ____                               _
// |  _\                             | |
// | |_)| __ _ ___  ___  ___ ___   __| | ___ TM
// |  _< / _` / __|/ _ \/ __/ _ \ / _` |/ _ \
// | |_)| (_| \__ \  __/ (_| (_) | (_| |  __/
// |____/\__,_|___/\___|\___\___/ \__,_|\___|
//
// V I R T U A L  M A C H I N E  P R O J E C T
//
// Copyright (C) 2020 Jeff Panici
// All rights reserved.
//
// This software source file is licensed under the terms of MIT license.
// For details, please read the LICENSE file.
//
// ----------------------------------------------------------------------------

#include <basecode/core/memory/system/stack.h>

namespace basecode::memory::stack {
    static u0 free(alloc_t* alloc, u0* mem, u32& freed_size) {
        auto h = system::header(mem);
        freed_size = h->size;
        alloc->total_allocated -= freed_size;
    }

    static u0* alloc(alloc_t* alloc, u32 size, u32 align, u32& alloc_size) {
        alloc_size = system::size_with_padding(size, align);
        auto h = (alloc_header_t*) alloca(alloc_size);
        auto p = system::data_pointer(h, align);
        system::fill(h, p, alloc_size);
        alloc->total_allocated += alloc_size;
        return p;
    }

    alloc_system_t                      g_stack_system{
        .init                           = {},
        .fini                           = {},
        .free                           = free,
        .alloc                          = alloc,
        .realloc                        = {},
        .type                           = alloc_type_t::stack,
    };

    alloc_system_t* system() {
        return &g_stack_system;
    }
}
