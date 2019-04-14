#include "lax_v1/arithmetic.hpp"
#include "lax_v1/core.hpp"
#include "lax_v1/functional.hpp"
#include "lax_v1/type_traits.hpp"

#include "config.hpp"

struct X;
struct Y;
struct Z;

static_assert(
    std::is_same_v<
        lax::force_deep_c<
            lax::seq_c<lax::add_m<>,
                       lax::add_m<lax::add_m<lax::auto_c<1>, lax::auto_c<2>>>,
                       lax::remove_pointer_m<lax::type_c<void *>>,
                       lax::seq_c<lax::add_m<lax::auto_c<1>, lax::auto_c<2>>>,
                       lax::fn_c<lax::seq_c<X, Y, Z>, lax::adds_m<X, Y, Z>>>>,
        lax::seq_c<
            lax::from_primitive_c<lax::add_p, 2>,
            lax::closure_c<lax::from_primitive_c<lax::add_p, 2>,
                           lax::add_m<lax::auto_c<1>, lax::auto_c<2>>>,
            lax::type_c<void>,
            lax::seq_c<lax::auto_c<3>>,
            lax::function_c<
                X,
                lax::function_c<Y,
                                lax::function_c<Z, lax::adds_m<X, Y, Z>>>>>>);
