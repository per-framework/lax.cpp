#pragma once

#include "lax_v1/synopsis.hpp"

#include <type_traits>

template <class Type, Type value>
struct lax_v1::value_t : std::integral_constant<Type, value> {
  using eval = value_t;
};
