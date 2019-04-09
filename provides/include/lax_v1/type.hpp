#pragma once

#include "lax_v1/type_synopsis.hpp"

template <class T> struct lax_v1::type_t {
  using eval = type_t;
  using type = T;
};
