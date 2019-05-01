#include "lax_v1/arithmetic.hpp"
#include "lax_v1/comparison.hpp"
#include "lax_v1/functional.hpp"
#include "lax_v1/type_traits.hpp"

#include "config.hpp"

static_assert(lax::apply_m<lax::compose_m<lax::neg_m<>, lax::neg_m<>>,
                           lax::auto_c<2>>::value == 2);

static_assert(lax::apply_m<lax::composes_m<lax::inc_m<>,
                                           lax::neg_m<>,
                                           lax::add_m<lax::auto_c<-1>>>,
                           lax::auto_c<1>>::value == 1);

static_assert(
    lax::apply_m<
        lax::pipes_m<lax::add_m<lax::auto_c<1>>, lax::neg_m<>, lax::dec_m<>>,
        lax::auto_c<1>>::value == -3);

static_assert(lax::thru_m<lax::auto_c<1>,
                          lax::add_m<lax::auto_c<1>>,
                          lax::neg_m<>,
                          lax::add_m<lax::auto_c<-1>>,
                          lax::eq_m<lax::auto_c<-3>>>::value == true);

struct V;

static_assert(lax::apply_m<lax::function_c<V, lax::add_m<V, lax::neg_m<V>>>,
                           lax::auto_c<1>>::value == 0);

static_assert(lax::thru_m<lax::type_c<short * [1]>,
                          lax::remove_all_extents_m<>,
                          lax::remove_pointer_m<>,
                          lax::alignment_of_m<>>::value == alignof(short));

static_assert(lax::thru_m<lax::auto_c<0>,
                          lax::div_m<lax::auto_c<0>>,
                          lax::constant_m<lax::auto_c<101>>>::value == 101);

template <class T>
using adhoc_t = lax::as_type_trait_t<
    lax::pipe_m<lax::remove_all_extents_m<>, lax::remove_pointer_m<>>,
    T>;

static_assert(std::is_same_v<adhoc_t<int * [2][2]>, int>);

template <class T>
inline constexpr auto adhoc_v = lax::as_value_trait_v<
    lax::pipe_m<lax::remove_all_extents_m<>, lax::alignment_of_m<>>,
    T>;

static_assert(adhoc_v<int * [2][2]> == alignof(int *));

struct F;

template <int value>
inline constexpr auto factorial_v = lax::apply_m<
    lax::fix_m<lax::fn_c<
        lax::seq_c<F, V>,
        lax::if_m<
            lax::eq_m<lax::auto_c<0>, V>,
            lax::auto_c<1>,
            lax::mul_m<V, lax::apply_m<F, lax::sub_m<V, lax::auto_c<1>>>>>>>,
    lax::auto_c<value>>::value;

static_assert(factorial_v<5> == 120);
