#include "lax_v1/logical.hpp"

#include "config.hpp"

static_assert(lax::value_of_v<lax::if_m<lax::and_m<>, lax::value_t<int, 1>,
                                        lax::value_t<int, 2>>> == 1);

static_assert(lax::value_of_v<lax::if_m<lax::or_m<>, lax::value_t<int, 1>,
                                        lax::value_t<int, 2>>> == 2);

static_assert(lax::value_of_v<lax::not_m<lax::false_t>>);
