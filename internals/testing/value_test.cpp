#include "lax_v1/core.hpp"

#include "config.hpp"

#include <type_traits>

static_assert(std::is_same_v<lax::auto_c<true>::value_type, bool>);

static_assert(std::is_same_v<lax::auto_c<'x'>::value_type, char>);
static_assert(std::is_same_v<lax::value_c<short, 101>::value_type, short>);
static_assert(std::is_same_v<lax::auto_c<101>::value_type, int>);
static_assert(
    std::is_same_v<lax::value_c<unsigned, 101u>::value_type, unsigned>);
static_assert(std::is_same_v<lax::value_c<long, 101l>::value_type, long>);
static_assert(std::is_same_v<lax::value_c<unsigned long, 101ul>::value_type,
                             unsigned long>);
static_assert(
    std::is_same_v<lax::value_c<unsigned long long, 101ull>::value_type,
                   unsigned long long>);
