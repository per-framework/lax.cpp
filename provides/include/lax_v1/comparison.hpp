#pragma once

#include "lax_v1/comparison_synopsis.hpp"
#include "lax_v1/value.hpp"

template <class LhsExpr, class RhsExpr>
struct lax_v1::lte_m
    : value_t<bool, (value_of_v<LhsExpr> <= value_of_v<RhsExpr>)> {};
