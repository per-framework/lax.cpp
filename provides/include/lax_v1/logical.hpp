#pragma once

#include "lax_v1/core.hpp"

namespace lax_v1 {
template <class Expr> using not_p = value_c<bool, !Expr::value>;
template <class Lhs, class Rhs> using and_p = force_c<if_p<Lhs, Rhs, false_c>>;
template <class Lhs, class Rhs> using or_p = force_c<if_p<Lhs, true_c, Rhs>>;
} // namespace lax_v1

template <class... Exprs>
struct lax_v1::and_m : primitive_c<and_p, 2, Exprs...> {};

template <class... Exprs>
struct lax_v1::or_m : primitive_c<or_p, 2, Exprs...> {};

template <class... Exprs>
struct lax_v1::not_m : primitive_c<not_p, 1, Exprs...> {};
