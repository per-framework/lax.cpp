#include "lax_v1/comparison.hpp"

#include "config.hpp"

static_assert(lax::gt_m<lax::auto_c<2>, lax::auto_c<1>>::value);

static_assert(!lax::eq_m<lax::auto_c<2>, lax::auto_c<1>>::value);
