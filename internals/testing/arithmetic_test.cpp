#include "lax_v1/arithmetic.hpp"

#include "config.hpp"

#include <type_traits>

static_assert(std::is_same_v<lax::force_c<lax::adds_m<lax::value_c<short, 1>,
                                                      lax::value_c<long, 2>>>,
                             lax::value_c<long, 3>>);

static_assert(
    std::is_same_v<lax::force_c<lax::mod_m<lax::auto_c<2>, lax::auto_c<2>>>,
                   lax::auto_c<0>>);

static_assert(std::is_same_v<
              lax::force_c<lax::muls_m<lax::auto_c<1>, lax::value_c<short, 2>>>,
              lax::auto_c<2>>);

static_assert(
    std::is_same_v<
        lax::force_c<lax::div_m<lax::value_c<short, 6>, lax::value_c<char, 2>>>,
        lax::auto_c<3>>);

static_assert(std::is_same_v<
              lax::force_c<lax::sub_m<lax::auto_c<3>, lax::value_c<char, 2>>>,
              lax::auto_c<1>>);

static_assert(std::is_same_v<lax::force_c<lax::neg_m<lax::value_c<short, 3>>>,
                             lax::auto_c<-3>>);
