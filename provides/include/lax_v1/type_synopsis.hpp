#pragma once

namespace lax_v1 {

template <class T> struct type_t;

template <class Expr> using type_of_t = typename Expr::eval::type;

} // namespace lax_v1
