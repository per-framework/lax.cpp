#pragma once

#include "lax_v1/synopsis.hpp"
#include "lax_v1/type.hpp"
#include "lax_v1/value.hpp"

template <template <class... Parameters> class Function, class... Arguments>
struct lax_v1::lazify_t : type_t<type_of_t<Function<type_of_t<Arguments>...>>> {
};

template <class Type,
          template <class... Parameters>
          class Function,
          class... Arguments>
struct lax_v1::lazify_v
    : value_t<Type, value_of_v<Function<type_of_t<Arguments>...>>> {};
