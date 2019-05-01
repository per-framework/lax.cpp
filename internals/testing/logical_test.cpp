#include "lax_v1/logical.hpp"

#include "config.hpp"

static_assert(lax::if_m<lax::ands_m<>, lax::auto_c<1>, lax::auto_c<2>>::value ==
              1);

static_assert(lax::if_m<lax::ors_m<>, lax::auto_c<1>, lax::auto_c<2>>::value ==
              2);

static_assert(!lax::and_m<lax::false_c,
                          lax::div_m<lax::auto_c<1>, lax::auto_c<0>>>::value);

static_assert(
    lax::or_m<lax::true_c, lax::div_m<lax::auto_c<1>, lax::auto_c<0>>>::value);

static_assert(lax::not_m<lax::false_c>::value);

static_assert(lax::switch_m<lax::case_c<lax::false_c, lax::auto_c<2>>,
                            lax::case_c<lax::true_c, lax::auto_c<1>>,
                            lax::default_c<lax::auto_c<3>>>::value == 1);
