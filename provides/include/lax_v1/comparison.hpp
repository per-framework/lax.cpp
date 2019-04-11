#pragma once

#include "lax_v1/comparison_synopsis.hpp"
#include "lax_v1/value.hpp"

template <class LhsExpr, class RhsExpr>
struct lax_v1::gt_m
    : value_t<bool, ((value_of_v<LhsExpr>) > (value_of_v<RhsExpr>))> {};

template <class LhsExpr, class RhsExpr>
struct lax_v1::gte_m
    : value_t<bool, ((value_of_v<LhsExpr>) >= (value_of_v<RhsExpr>))> {};

template <class LhsExpr, class RhsExpr>
struct lax_v1::lt_m
    : value_t<bool, ((value_of_v<LhsExpr>) < (value_of_v<RhsExpr>))> {};

template <class LhsExpr, class RhsExpr>
struct lax_v1::lte_m
    : value_t<bool, ((value_of_v<LhsExpr>) <= (value_of_v<RhsExpr>))> {};
