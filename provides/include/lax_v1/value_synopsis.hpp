#pragma once

#include "lax_v1/type_synopsis.hpp"

namespace lax_v1 {

template <class Type, Type value> struct value_t;

template <class Expr> using value_type_of_t = typename Expr::value_type;

template <class Expr>
inline constexpr value_type_of_t<Expr> value_of_v = Expr::value;

using true_t = value_t<bool, true>;
using false_t = value_t<bool, false>;

} // namespace lax_v1
