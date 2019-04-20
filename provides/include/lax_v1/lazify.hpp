#pragma once

#include "lax_v1/synopsis.hpp"
#include "lax_v1/type.hpp"
#include "lax_v1/value.hpp"

template <template <class... Formals> class Trait, class... Actuals>
struct lax_v1::lazify_t : type_t<type_of_t<Trait<type_of_t<Actuals>...>>> {};

template <class Type, template <class... Formals> class Trait, class... Actuals>
struct lax_v1::lazify_v
    : value_t<Type, value_of_v<Trait<type_of_t<Actuals>...>>> {};
