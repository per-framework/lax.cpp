#pragma once

#include "lax_v1/type_synopsis.hpp"

namespace lax_v1 {

template <class Type, Type value> struct value_t;

template <class Expr>
inline constexpr type_of_t<Expr> value_of_v = Expr::eval::value;

using true_t = value_t<bool, true>;
using false_t = value_t<bool, false>;

} // namespace lax_v1
