#include "lax_v1/arithmetic.hpp"
#include "lax_v1/force.hpp"

#include "config.hpp"

#include <type_traits>

static_assert(
    std::is_same_v<
        lax::force_t<lax::add_m<lax::value_t<short, 1>, lax::value_t<long, 2>>>,
        lax::value_t<long, 3>>);

static_assert(
    std::is_same_v<
        lax::force_t<lax::mod_m<lax::value_t<int, 2>, lax::value_t<int, 2>>>,
        lax::value_t<int, 0>>);

static_assert(
    std::is_same_v<
        lax::force_t<lax::mul_m<lax::value_t<int, 1>, lax::value_t<short, 2>>>,
        lax::value_t<int, 2>>);

static_assert(
    std::is_same_v<
        lax::force_t<lax::div_m<lax::value_t<short, 6>, lax::value_t<char, 2>>>,
        lax::value_t<int, 3>>);

static_assert(
    std::is_same_v<
        lax::force_t<lax::sub_m<lax::value_t<int, 3>, lax::value_t<char, 2>>>,
        lax::value_t<int, 1>>);

static_assert(std::is_same_v<lax::force_t<lax::neg_m<lax::value_t<short, 3>>>,
                             lax::value_t<int, -3>>);
