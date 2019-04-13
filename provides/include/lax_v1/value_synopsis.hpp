#pragma once

#include "lax_v1/type_synopsis.hpp"

namespace lax_v1 {

template <class Type, Type value> struct value_t;

template <class Expr> using value_type_of_t = typename Expr::value_type;

template <class Expr>
inline constexpr value_type_of_t<Expr> value_of_v = Expr::value;

template <auto value> using auto_t = value_t<decltype(value), value>;

using true_t = auto_t<true>;
using false_t = auto_t<false>;

} // namespace lax_v1
