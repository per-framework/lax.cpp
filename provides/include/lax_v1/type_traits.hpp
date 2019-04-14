#pragma once

#include "lax_v1/core.hpp"

template <class... Exprs>
struct lax_v1::alignment_of_m
    : value_trait_c<std::alignment_of, 1, size_t, Exprs...> {};

//

template <class... Exprs>
struct lax_v1::is_array_m : value_trait_c<std::is_array, 1, bool, Exprs...> {};

template <class... Exprs>
struct lax_v1::is_pointer_m
    : value_trait_c<std::is_pointer, 1, bool, Exprs...> {};

//

template <class... Exprs>
struct lax_v1::is_same_m : value_trait_c<std::is_same, 2, bool, Exprs...> {};

//

template <class... Exprs>
struct lax_v1::remove_all_extents_m
    : type_trait_c<std::remove_all_extents, 1, Exprs...> {};

template <class... Exprs>
struct lax_v1::remove_pointer_m
    : type_trait_c<std::remove_pointer, 1, Exprs...> {};
