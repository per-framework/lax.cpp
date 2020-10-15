#include "lax_v1/arithmetic.hpp"
#include "lax_v1/functional.hpp"

#include "config.hpp"

static_assert(lax::value_of_v<lax::apply_m<
                  lax::compose_m<lax::fn_t<lax::neg_m>, lax::fn_t<lax::neg_m>>,
                  lax::value_t<int, 2>>> == 2);

static_assert(
    lax::value_of_v<lax::apply_m<
        lax::compose_m<lax::fn_t<lax::add_m, 2, lax::value_t<int, 1>>,
                       lax::fn_t<lax::neg_m>,
                       lax::fn_t<lax::add_m, 2, lax::value_t<int, -1>>>,
        lax::value_t<int, 1>>> == 1);

static_assert(lax::value_of_v<lax::apply_m<
                  lax::pipe_m<lax::fn_t<lax::add_m, 2, lax::value_t<int, 1>>,
                              lax::fn_t<lax::neg_m>,
                              lax::fn_t<lax::add_m, 2, lax::value_t<int, -1>>>,
                  lax::value_t<int, 1>>> == -3);

static_assert(
    lax::value_of_v<
        lax::thru_m<lax::value_t<int, 1>,
                    lax::fn_t<lax::add_m, 2, lax::value_t<int, 1>>,
                    lax::fn_t<lax::neg_m>,
                    lax::fn_t<lax::add_m, 2, lax::value_t<int, -1>>>> == -3);
