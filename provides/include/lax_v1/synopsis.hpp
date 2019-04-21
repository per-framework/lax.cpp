#pragma once

namespace lax_v1 {

// force.hpp ===================================================================

template <class Expr> using force_t = typename Expr::eval;

// type.hpp ====================================================================

template <class T> struct type_t;

template <class Expr> using type_of_t = typename Expr::type;

// value.hpp ===================================================================

template <class Type, Type value> struct value_t;

template <class Expr> using value_type_of_t = typename Expr::value_type;

template <class Expr>
inline constexpr value_type_of_t<Expr> value_of_v = Expr::value;

template <auto value> using auto_t = value_t<decltype(value), value>;

using true_t = auto_t<true>;
using false_t = auto_t<false>;

// arithmetic.hpp ==============================================================

template <class Lhs, class Rhs> struct add_m;
template <class Lhs, class Rhs> struct div_m;
template <class Lhs, class Rhs> struct mod_m;
template <class Lhs, class Rhs> struct mul_m;
template <class Lhs, class Rhs> struct sub_m;

template <class Expr> struct neg_m;

// comparison.hpp ==============================================================

template <class Lhs, class Rhs> struct eq_m;
template <class Lhs, class Rhs> struct gt_m;
template <class Lhs, class Rhs> struct gte_m;
template <class Lhs, class Rhs> struct lt_m;
template <class Lhs, class Rhs> struct lte_m;

// logical.hpp =================================================================

template <class... Exprs> struct if_m;

template <class... Exprs> struct and_m;
template <class... Exprs> struct or_m;

template <class Expr> struct not_m;

// lazify.hpp ==================================================================

template <template <class... Formals> class Trait, class... Actuals>
using lazify_type_trait_t = type_t<type_of_t<Trait<type_of_t<Actuals>...>>>;

template <class Type, template <class... Formals> class Trait, class... Actuals>
using lazify_value_trait_t =
    value_t<Type, value_of_v<Trait<type_of_t<Actuals>...>>>;

// type_traits.hpp =============================================================

template <class TypeExpr> struct alignment_of_m;

template <class TypeExpr> struct is_array_m;
template <class TypeExpr> struct is_pointer_m;
template <class LhsTypeExpr, class RhsTypeExpr> struct is_same_m;

template <class TypeExpr> struct remove_all_extents_m;
template <class TypeExpr> struct remove_pointer_m;

} // namespace lax_v1
