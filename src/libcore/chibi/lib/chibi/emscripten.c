/* Automatically generated by chibi-ffi; version: 0.4 */

#include <chibi/eval.h>
/*
types: ()
enums: ()
*/


sexp sexp_init_library (sexp ctx, sexp self, sexp_sint_t n, sexp env, const char* version, const sexp_abi_identifier_t abi) {
  sexp_gc_var3(name, tmp, op);
  if (!(sexp_version_compatible(ctx, version, sexp_version)
        && sexp_abi_compatible(ctx, abi, SEXP_ABI_IDENTIFIER)))
    return SEXP_ABI_ERROR;
  sexp_gc_preserve3(ctx, name, tmp, op);
  sexp_gc_release3(ctx);
  return SEXP_VOID;
}

