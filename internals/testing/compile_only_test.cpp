#include "lax_v1/comparison.hpp"
#include "lax_v1/logical.hpp"
#include "lax_v1/type.hpp"
#include "lax_v1/type_traits.hpp"
#include "lax_v1/value.hpp"

#include <type_traits>

namespace lax = lax_v1;

static_assert(std::is_same_v<lax::value_t<bool, true>::value_type, bool>);

static_assert(std::is_same_v<lax::value_t<char, 'x'>::value_type, char>);
static_assert(std::is_same_v<lax::value_t<short, 101>::value_type, short>);
static_assert(std::is_same_v<lax::value_t<int, 101>::value_type, int>);
static_assert(
    std::is_same_v<lax::value_t<unsigned, 101u>::value_type, unsigned>);
static_assert(std::is_same_v<lax::value_t<long, 101l>::value_type, long>);
static_assert(std::is_same_v<lax::value_t<unsigned long, 101ul>::value_type,
                             unsigned long>);
static_assert(
    std::is_same_v<lax::value_t<unsigned long long, 101ull>::value_type,
                   unsigned long long>);

static_assert(lax::value_of_v<lax::is_array_m<lax::type_t<int[2]>>>);

static_assert(lax::value_of_v<lax::not_m<lax::false_t>>);

static_assert(
    lax::value_of_v<lax::gt_m<lax::value_t<int, 2>, lax::value_t<int, 1>>>);

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
static_assert(is_stored_plain_v<int * [2]>);

int main() { return 0; }
