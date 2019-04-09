#pragma once

#include "lax_v1/type.hpp"
#include "lax_v1/value_synopsis.hpp"

template <class Type, Type value_> struct lax_v1::value_t {
  using eval = value_t;
  using type = Type;
  static constexpr Type value = value_;
};
