#include "lax_v1/comparison.hpp"

#include "config.hpp"

static_assert(
    lax::value_of_v<lax::gt_m<lax::value_t<int, 2>, lax::value_t<int, 1>>>);
