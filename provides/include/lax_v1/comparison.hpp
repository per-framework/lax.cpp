#pragma once

#include "lax_v1/core.hpp"

#define LAX(name, op)                                                          \
  namespace lax_v1 {                                                           \
  template <class Lhs, class Rhs>                                              \
  using name##_p = value_c<bool, (Lhs::value op Rhs::value)>;                  \
  }                                                                            \
  template <class... Exprs>                                                    \
  struct lax_v1::name##_m : primitive_c<name##_p, 2, Exprs...> {};

LAX(eq, ==)
LAX(gt, >)
LAX(gte, >=)
LAX(lt, <)
LAX(lte, <=)
LAX(neq, !=)
#undef LAX
