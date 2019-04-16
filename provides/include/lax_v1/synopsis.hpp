#pragma once

namespace lax_v1 {

// type.hpp --------------------------------------------------------------------

template <class T> struct type_t;

template <class Expr> using type_of_t = typename Expr::type;

// value.hpp -------------------------------------------------------------------

template <class Type, Type value> struct value_t;

template <class Expr> using value_type_of_t = typename Expr::value_type;

template <class Expr>
inline constexpr value_type_of_t<Expr> value_of_v = Expr::value;

template <auto value> using auto_t = value_t<decltype(value), value>;

using true_t = auto_t<true>;
using false_t = auto_t<false>;

// arithmetic.hpp --------------------------------------------------------------

template <class LhsExpr, class RhsExpr> struct add_m;
template <class LhsExpr, class RhsExpr> struct div_m;
template <class LhsExpr, class RhsExpr> struct mod_m;
template <class LhsExpr, class RhsExpr> struct mul_m;
template <class LhsExpr, class RhsExpr> struct sub_m;

template <class Expr> struct neg_m;

// comparison.hpp --------------------------------------------------------------

template <class LhsExpr, class RhsExpr> struct eq_m;
template <class LhsExpr, class RhsExpr> struct gt_m;
template <class LhsExpr, class RhsExpr> struct gte_m;
template <class LhsExpr, class RhsExpr> struct lt_m;
template <class LhsExpr, class RhsExpr> struct lte_m;

// logical.hpp -----------------------------------------------------------------

template <class... Exprs> struct if_m;

template <class... Exprs> struct and_m;
template <class... Exprs> struct or_m;

template <class Expr> struct not_m;

// force.hpp -------------------------------------------------------------------

template <class Expr> using force_t = typename Expr::eval;

// lazify.hpp ------------------------------------------------------------------

template <template <class... Parameters> class Function, class... Arguments>
struct lazify_t;

template <class Type, template <class... Parameters> class Function,
          class... Arguments>
struct lazify_v;

// type_traits.hpp -------------------------------------------------------------

template <class TypeExpr> struct alignment_of_m;

template <class TypeExpr> struct is_array_m;
template <class TypeExpr> struct is_pointer_m;
template <class LhsTypeExpr, class RhsTypeExpr> struct is_same_m;

template <class TypeExpr> struct remove_all_extents_m;
template <class TypeExpr> struct remove_pointer_m;

} // namespace lax_v1
