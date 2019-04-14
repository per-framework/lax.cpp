#include "lax_v1/arithmetic.hpp"
#include "lax_v1/functional.hpp"
#include "lax_v1/seq.hpp"
#include "lax_v1/value.hpp"

#include "config.hpp"

#include <type_traits>

using values_t = lax::Seq::t<lax::value_t<int, 3>,
                             lax::value_t<int, 1>,
                             lax::value_t<int, 4>,
                             lax::value_t<int, 1>,
                             lax::value_t<int, 5>,
                             lax::value_t<int, 9>>;

static_assert(lax::value_of_v<lax::Seq::length_m<values_t>> == 6);

static_assert(std::is_same_v<
              lax::force_t<lax::Seq::map_m<lax::fn_t<lax::neg_m>, values_t>>,
              lax::Seq::t<lax::value_t<int, -3>,
                          lax::value_t<int, -1>,
                          lax::value_t<int, -4>,
                          lax::value_t<int, -1>,
                          lax::value_t<int, -5>,
                          lax::value_t<int, -9>>>);
