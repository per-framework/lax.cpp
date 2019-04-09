#pragma once

#include "lax_v1/lazify.hpp"
#include "lax_v1/type_traits_synopsis.hpp"

#include <cstddef>
#include <type_traits>

template <class T>
struct lax_v1::alignment_of_m : lazify_v<size_t, std::alignment_of, T> {};

template <class T>
struct lax_v1::is_array_m : lazify_v<bool, std::is_array, T> {};

template <class T>
struct lax_v1::is_pointer_m : lazify_v<bool, std::is_pointer, T> {};

template <class T>
struct lax_v1::remove_all_extents_m : lazify_t<std::remove_all_extents, T> {};

template <class T>
struct lax_v1::remove_pointer_m : lazify_t<std::remove_pointer, T> {};
