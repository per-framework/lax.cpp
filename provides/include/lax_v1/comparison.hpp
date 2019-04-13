#pragma once

#include "lax_v1/comparison_synopsis.hpp"
#include "lax_v1/value.hpp"

template <class LhsExpr, class RhsExpr>
struct lax_v1::gt_m : auto_t<(value_of_v<LhsExpr>> value_of_v<RhsExpr>)> {};

template <class LhsExpr, class RhsExpr>
struct lax_v1::gte_m : auto_t<(value_of_v<LhsExpr> >= value_of_v<RhsExpr>)> {};

template <class LhsExpr, class RhsExpr>
struct lax_v1::lt_m : auto_t<(value_of_v<LhsExpr> < value_of_v<RhsExpr>)> {};

template <class LhsExpr, class RhsExpr>
struct lax_v1::lte_m : auto_t<(value_of_v<LhsExpr> <= value_of_v<RhsExpr>)> {};
