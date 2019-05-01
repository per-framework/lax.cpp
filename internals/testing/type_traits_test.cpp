#include "lax_v1/comparison.hpp"
#include "lax_v1/logical.hpp"
#include "lax_v1/type_traits.hpp"

#include "config.hpp"

static_assert(lax::is_array_m<lax::type_c<int[2]>>::value);

template <class Value>
struct is_stored_plain_m
    : lax::or_m<
          lax::and_m<
              lax::is_pointer_m<Value>,
              lax::lte_m<lax::auto_c<2>,
                         lax::alignment_of_m<lax::remove_pointer_m<Value>>>>,
          lax::and_m<lax::is_array_m<Value>,
                     is_stored_plain_m<lax::remove_all_extents_m<Value>>>> {};

template <class Value>
static inline constexpr bool is_stored_plain_v =
    is_stored_plain_m<lax::type_c<Value>>::value;

static_assert(!is_stored_plain_v<char>);
static_assert(!is_stored_plain_v<char *>);
static_assert(is_stored_plain_v<int *>);
static_assert(is_stored_plain_v<int * [2]>);

static_assert(!lax::is_same_m<lax::type_c<void>, lax::type_c<int>>::value);
