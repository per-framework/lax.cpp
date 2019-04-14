#pragma once

#include "lax_v1/core.hpp"

#include <type_traits>

#define LAX(name, op)                                                          \
  namespace lax_v1 {                                                           \
  template <class Lhs, class Rhs>                                              \
  using name##_p = value_c<                                                    \
      std::common_type_t<typename Lhs::value_type, typename Rhs::value_type>,  \
      Lhs::value op Rhs::value>;                                               \
  }                                                                            \
  template <class... Exprs>                                                    \
  struct lax_v1::name##_m : primitive_c<name##_p, 2, Exprs...> {};

LAX(add, +)
LAX(div, /)
LAX(mod, %)
LAX(mul, *)
LAX(sub, -)
#undef LAX

namespace lax_v1 {
template <class Expr> using neg_p = auto_c<-Expr::value>;
} // namespace lax_v1

template <class... Exprs>
struct lax_v1::neg_m : primitive_c<neg_p, 1, Exprs...> {};
