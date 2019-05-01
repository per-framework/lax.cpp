#pragma once

#include "lax_v1/core.hpp"

//

template <class... Exprs>
struct lax_v1::identity_m : primitive_c<force_c, 1, Exprs...> {};

//

template <class... Exprs>
struct lax_v1::constant_m : primitive_c<if_p, 3, true_c, Exprs...> {};

//

namespace lax_v1 {
template <class Function1, class Function2> struct compose_p {
  using eval = compose_p;
  static constexpr size_t arity = 1;
  template <class Expr>
  struct template_m : force_c<apply_m<Function1, apply_m<Function2, Expr>>> {};
};
} // namespace lax_v1

template <class... Functions>
struct lax_v1::compose_m : primitive_c<compose_p, 2, Functions...> {};

//

namespace lax_v1 {
template <class Function1, class Function2> struct pipe_p {
  using eval = pipe_p;
  static constexpr size_t arity = 1;
  template <class Expr>
  struct template_m : force_c<apply_m<Function2, apply_m<Function1, Expr>>> {};
};
} // namespace lax_v1

template <class... Functions>
struct lax_v1::pipe_m : primitive_c<pipe_p, 2, Functions...> {};

//

template <class Expr, class... Functions>
struct lax_v1::thru_m : force_c<apply_m<pipes_m<Functions...>, Expr>> {};

//

namespace lax_v1 {
template <class Function>
struct fix_p : force_c<apply_m<force_c<Function>, fix_p<force_c<Function>>>> {};
} // namespace lax_v1

template <class... Function>
struct lax_v1::fix_m : primitive_c<fix_p, 1, Function...> {};
