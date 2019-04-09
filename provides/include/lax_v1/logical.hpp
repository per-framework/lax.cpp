#pragma once

#include "lax_v1/force.hpp"
#include "lax_v1/logical_synopsis.hpp"
#include "lax_v1/value.hpp"

template <class... Exprs> struct lax_v1::and_m : true_t {};
template <class... Exprs>
struct lax_v1::and_m<lax_v1::false_t, Exprs...> : false_t {};
template <class... Exprs>
struct lax_v1::and_m<lax_v1::true_t, Exprs...> : and_m<Exprs...> {};
template <class Expr, class... Exprs>
struct lax_v1::and_m<Expr, Exprs...> : and_m<force_t<Expr>, Exprs...> {};

template <class... Exprs> struct lax_v1::or_m : false_t {};
template <class... Exprs>
struct lax_v1::or_m<lax_v1::true_t, Exprs...> : true_t {};
template <class... Exprs>
struct lax_v1::or_m<lax_v1::false_t, Exprs...> : or_m<Exprs...> {};
template <class Expr, class... Exprs>
struct lax_v1::or_m<Expr, Exprs...> : lax_v1::or_m<force_t<Expr>, Exprs...> {};
