#pragma once

#include "lax_v1/synopsis.hpp"

#include "lax_v1/value.hpp"

#include <type_traits>

template <class Lhs, class Rhs>
struct lax_v1::add_m
    : value_t<std::common_type_t<value_type_of_t<Lhs>, value_type_of_t<Rhs>>,
              value_of_v<Lhs> + value_of_v<Rhs>> {};

template <class Lhs, class Rhs>
struct lax_v1::div_m
    : value_t<std::common_type_t<value_type_of_t<Lhs>, value_type_of_t<Rhs>>,
              value_of_v<Lhs> / value_of_v<Rhs>> {};

template <class Lhs, class Rhs>
struct lax_v1::mod_m
    : value_t<std::common_type_t<value_type_of_t<Lhs>, value_type_of_t<Rhs>>,
              value_of_v<Lhs> % value_of_v<Rhs>> {};

template <class Lhs, class Rhs>
struct lax_v1::mul_m
    : value_t<std::common_type_t<value_type_of_t<Lhs>, value_type_of_t<Rhs>>,
              value_of_v<Lhs> * value_of_v<Rhs>> {};

template <class Lhs, class Rhs>
struct lax_v1::sub_m
    : value_t<std::common_type_t<value_type_of_t<Lhs>, value_type_of_t<Rhs>>,
              value_of_v<Lhs> - value_of_v<Rhs>> {};

template <class Expr> struct lax_v1::neg_m : auto_t<-value_of_v<Expr>> {};
