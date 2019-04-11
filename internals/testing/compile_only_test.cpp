#include "lax_v1/comparison.hpp"
#include "lax_v1/logical.hpp"
#include "lax_v1/type.hpp"
#include "lax_v1/type_traits.hpp"
#include "lax_v1/value.hpp"

#include <type_traits>

namespace lax = lax_v1;

static_assert(std::is_same_v<lax::value_t<bool, true>::type, bool>);

static_assert(std::is_same_v<lax::value_t<char, 'x'>::type, char>);
static_assert(std::is_same_v<lax::value_t<short, 101>::type, short>);
static_assert(std::is_same_v<lax::value_t<int, 101>::type, int>);
static_assert(std::is_same_v<lax::value_t<unsigned, 101u>::type, unsigned>);
static_assert(std::is_same_v<lax::value_t<long, 101l>::type, long>);
static_assert(
    std::is_same_v<lax::value_t<unsigned long, 101ul>::type, unsigned long>);
static_assert(std::is_same_v<lax::value_t<unsigned long long, 101ull>::type,
                             unsigned long long>);

static_assert(lax::value_of_v<lax::is_array_m<lax::type_t<int[2]>>>);

static_assert(lax::value_of_v<lax::not_m<lax::false_t>>);

int main() { return 0; }
