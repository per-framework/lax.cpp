#include "lax_v1/arithmetic.hpp"
#include "lax_v1/functional.hpp"
#include "lax_v1/tycon.hpp"

#include "config.hpp"

struct V;

static_assert(
    lax::value_of_v<lax::apply_m<lax::tycon_f<V, lax::add_m<V, lax::neg_m<V>>>,
                                 lax::value_t<int, 1>>> == 0);
