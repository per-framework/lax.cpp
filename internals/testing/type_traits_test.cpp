#include "lax_v1/comparison.hpp"
#include "lax_v1/logical.hpp"
#include "lax_v1/type_traits.hpp"

#include "config.hpp"

static_assert(lax::value_of_v<lax::is_array_m<lax::type_t<int[2]>>>);

template <class Value>
struct is_stored_plain_m
    : lax::or_m<
          lax::and_m<
              lax::is_pointer_m<Value>,
              lax::lte_m<lax::value_t<size_t, 2>,
                         lax::alignment_of_m<lax::remove_pointer_m<Value>>>>,
          lax::and_m<lax::is_array_m<Value>,
                     is_stored_plain_m<lax::remove_all_extents_m<Value>>>> {};

template <class Value>
static inline constexpr bool is_stored_plain_v =
    lax::value_of_v<is_stored_plain_m<lax::type_t<Value>>>;

static_assert(!is_stored_plain_v<char>);
static_assert(!is_stored_plain_v<char *>);
static_assert(is_stored_plain_v<int *>);
static_assert(is_stored_plain_v<int *[2]>);
