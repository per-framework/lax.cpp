#pragma once

#include "lax_v1/logical.hpp"
#include "lax_v1/synopsis.hpp"

template <template <class... Formals> class Function,
          size_t arity,
          class... BoundActuals>
struct lax_v1::fn_t {
  using eval = fn_t;
  template <class... Actuals>
  struct m
      : force_t<
            if_m<auto_t<(sizeof...(BoundActuals) + sizeof...(Actuals) < arity)>,
                 fn_t<Function, arity, BoundActuals..., Actuals...>,
                 Function<BoundActuals..., Actuals...>>> {};
};

//

template <class Function, class... Actuals>
struct lax_v1::apply_m : force_t<typename Function::template m<Actuals...>> {};

//

struct lax_v1::identity_m {
  using eval = identity_m;
  template <class Expr> struct m : force_t<Expr> {};
};

//

template <> struct lax_v1::compose_m<> : identity_m {};

template <class Function>
struct lax_v1::compose_m<Function> : force_t<Function> {};

template <class Function1, class Function2, class... Functions>
struct lax_v1::compose_m<Function1, Function2, Functions...> {
  using eval = compose_m;
  template <class Expr>
  struct m
      : force_t<apply_m<Function1,
                        apply_m<compose_m<Function2, Functions...>, Expr>>> {};
};

//

template <> struct lax_v1::pipe_m<> : identity_m {};

template <class Function>
struct lax_v1::pipe_m<Function> : force_t<Function> {};

template <class Function1, class Function2, class... Functions>
struct lax_v1::pipe_m<Function1, Function2, Functions...> {
  using eval = pipe_m;
  template <class Expr>
  struct m : force_t<apply_m<pipe_m<Function2, Functions...>,
                             apply_m<Function1, Expr>>> {};
};

//

template <class Expr> struct lax_v1::thru_m<Expr> : force_t<Expr> {};

template <class Expr, class Function>
struct lax_v1::thru_m<Expr, Function> : force_t<apply_m<Function, Expr>> {};

template <class Expr, class Function, class... Functions>
struct lax_v1::thru_m<Expr, Function, Functions...>
    : force_t<thru_m<apply_m<Function, Expr>, Functions...>> {};
