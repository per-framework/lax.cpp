#pragma once

#include "lax_v1/force.hpp"
#include "lax_v1/logical_synopsis.hpp"
#include "lax_v1/value.hpp"

template <class ElseExpr> struct lax_v1::if_m<ElseExpr> : force_t<ElseExpr> {};
template <class CondExpr, class ThenExpr, class... ElseExprs>
struct lax_v1::if_m<CondExpr, ThenExpr, ElseExprs...>
    : if_m<force_t<CondExpr>, ThenExpr, ElseExprs...> {};
template <class ThenExpr, class... ElseExprs>
struct lax_v1::if_m<lax_v1::true_t, ThenExpr, ElseExprs...> : ThenExpr {};
template <class ThenExpr, class... ElseExprs>
struct lax_v1::if_m<lax_v1::false_t, ThenExpr, ElseExprs...>
    : if_m<ElseExprs...> {};

template <> struct lax_v1::and_m<> : true_t {};
template <class... Exprs>
struct lax_v1::and_m<lax_v1::false_t, Exprs...> : false_t {};
template <class... Exprs>
struct lax_v1::and_m<lax_v1::true_t, Exprs...> : and_m<Exprs...> {};
template <class Expr, class... Exprs>
struct lax_v1::and_m<Expr, Exprs...> : and_m<force_t<Expr>, Exprs...> {};

template <class Expr>
struct lax_v1::not_m : value_t<bool, !value_of_v<Expr>> {};

template <> struct lax_v1::or_m<> : false_t {};
template <class... Exprs>
struct lax_v1::or_m<lax_v1::true_t, Exprs...> : true_t {};
template <class... Exprs>
struct lax_v1::or_m<lax_v1::false_t, Exprs...> : or_m<Exprs...> {};
template <class Expr, class... Exprs>
struct lax_v1::or_m<Expr, Exprs...> : or_m<force_t<Expr>, Exprs...> {};
