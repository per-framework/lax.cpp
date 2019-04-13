#include "lax_v1/value.hpp"

#include "config.hpp"

#include <type_traits>

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
