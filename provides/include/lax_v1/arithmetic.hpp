#pragma once

#include "lax_v1/synopsis.hpp"

#include "lax_v1/value.hpp"

#include <type_traits>

template <class LhsExpr, class RhsExpr>
struct lax_v1::add_m : value_t<std::common_type_t<value_type_of_t<LhsExpr>,
                                                  value_type_of_t<RhsExpr>>,
                               value_of_v<LhsExpr> + value_of_v<RhsExpr>> {};

template <class LhsExpr, class RhsExpr>
struct lax_v1::div_m : value_t<std::common_type_t<value_type_of_t<LhsExpr>,
                                                  value_type_of_t<RhsExpr>>,
                               value_of_v<LhsExpr> / value_of_v<RhsExpr>> {};

template <class LhsExpr, class RhsExpr>
struct lax_v1::mod_m : value_t<std::common_type_t<value_type_of_t<LhsExpr>,
                                                  value_type_of_t<RhsExpr>>,
                               value_of_v<LhsExpr> % value_of_v<RhsExpr>> {};

template <class LhsExpr, class RhsExpr>
struct lax_v1::mul_m : value_t<std::common_type_t<value_type_of_t<LhsExpr>,
                                                  value_type_of_t<RhsExpr>>,
                               value_of_v<LhsExpr> * value_of_v<RhsExpr>> {};

template <class LhsExpr, class RhsExpr>
struct lax_v1::sub_m : value_t<std::common_type_t<value_type_of_t<LhsExpr>,
                                                  value_type_of_t<RhsExpr>>,
                               value_of_v<LhsExpr> - value_of_v<RhsExpr>> {};

template <class Expr> struct lax_v1::neg_m : auto_t<-value_of_v<Expr>> {};
