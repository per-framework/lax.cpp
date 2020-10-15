#pragma once

#include "lax_v1/type.hpp"

namespace lax_v1 {

class tycon_private {
  template <class Formal, class Expr> friend struct tycon_f;

  template <class Formal, class Actual, class Expr> struct subst_m;

  template <class Formal, class Actual, class Expr>
  using subst_t = type_of_t<subst_m<Formal, Actual, Expr>>;
};

} // namespace lax_v1

template <class Formal, class Expr> struct lax_v1::tycon_f {
  using eval = tycon_f;
  template <class Actual>
  struct m : tycon_private::subst_t<Formal, Actual, Expr> {};
};

//

template <class Formal, class Actual>
struct lax_v1::tycon_private::subst_m<Formal, Actual, Formal> : type_t<Actual> {
};

template <class Formal, class Actual, class Expr>
struct lax_v1::tycon_private::
    subst_m<Formal, Actual, lax_v1::tycon_f<Formal, Expr>>
    : type_t<tycon_f<Formal, Expr>> {};

template <class Formal,
          class Actual,
          template <class... Formals>
          class Function,
          class... Exprs>
struct lax_v1::tycon_private::subst_m<Formal, Actual, Function<Exprs...>>
    : type_t<Function<subst_t<Formal, Actual, Exprs>...>> {};

template <class Formal,
          class Actual,
          template <template <class... Formals> class F, class... As>
          class R,
          template <class... Formals>
          class F,
          class... Exprs>
struct lax_v1::tycon_private::subst_m<Formal, Actual, R<F, Exprs...>>
    : type_t<R<F, subst_t<Formal, Actual, Exprs>...>> {};

template <class Formal, class Actual, class ReturnType, class... ParamTypes>
struct lax_v1::tycon_private::subst_m<Formal, Actual, ReturnType(ParamTypes...)>
    : type_t<subst_t<Formal, Actual, ReturnType>(
          subst_t<Formal, Actual, ParamTypes>...)> {};
