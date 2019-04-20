#pragma once

#include "lax_v1/force.hpp"
#include "lax_v1/synopsis.hpp"
#include "lax_v1/value.hpp"

template <class Else> struct lax_v1::if_m<Else> : force_t<Else> {};
template <class Cond, class Then, class... Elses>
struct lax_v1::if_m<Cond, Then, Elses...>
    : if_m<force_t<Cond>, Then, Elses...> {};
template <class Then, class... Elses>
struct lax_v1::if_m<lax_v1::true_t, Then, Elses...> : Then {};
template <class Then, class... Elses>
struct lax_v1::if_m<lax_v1::false_t, Then, Elses...> : if_m<Elses...> {};

template <> struct lax_v1::and_m<> : true_t {};
template <class Expr, class... Exprs>
struct lax_v1::and_m<Expr, Exprs...> : if_m<Expr, and_m<Exprs...>, false_t> {};

template <class Expr> struct lax_v1::not_m : auto_t<!value_of_v<Expr>> {};

template <> struct lax_v1::or_m<> : false_t {};
template <class Expr, class... Exprs>
struct lax_v1::or_m<Expr, Exprs...> : if_m<Expr, true_t, or_m<Exprs...>> {};
