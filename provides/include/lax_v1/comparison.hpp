#pragma once

#include "lax_v1/synopsis.hpp"
#include "lax_v1/value.hpp"

template <class Lhs, class Rhs>
struct lax_v1::eq_m : auto_t<(value_of_v<Lhs> == value_of_v<Rhs>)> {};

template <class Lhs, class Rhs>
struct lax_v1::gt_m : auto_t<(value_of_v<Lhs>> value_of_v<Rhs>)> {};

template <class Lhs, class Rhs>
struct lax_v1::gte_m : auto_t<(value_of_v<Lhs> >= value_of_v<Rhs>)> {};

template <class Lhs, class Rhs>
struct lax_v1::lt_m : auto_t<(value_of_v<Lhs> < value_of_v<Rhs>)> {};

template <class Lhs, class Rhs>
struct lax_v1::lte_m : auto_t<(value_of_v<Lhs> <= value_of_v<Rhs>)> {};
