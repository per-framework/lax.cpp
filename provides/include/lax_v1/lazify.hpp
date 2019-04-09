#pragma once

#include "lax_v1/lazify_synopsis.hpp"
#include "lax_v1/type.hpp"
#include "lax_v1/value.hpp"

template <template <class... Parameters> class Function, class... Arguments>
struct lax_v1::lazify_t
    : type_t<typename Function<type_of_t<Arguments>...>::type> {};

template <class Type, template <class... Parameters> class Function,
          class... Arguments>
struct lax_v1::lazify_v
    : value_t<Type, Function<type_of_t<Arguments>...>::value> {};
