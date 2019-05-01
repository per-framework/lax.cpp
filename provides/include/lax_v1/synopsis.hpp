#pragma once

#include <cstddef>

namespace lax_v1 {

// core.hpp ====================================================================

/// Evaluates an expression to weak head normal form.
template <class Expr> using force_c = typename Expr::eval;

/// Implementation detail of `force_deep_c`.
template <class Expr> struct force_deep_from_whnf_m;

/// Evaluates an expression to a normal form.
template <class Expr>
using force_deep_c = force_c<force_deep_from_whnf_m<force_c<Expr>>>;

// -----------------------------------------------------------------------------

/// Wraps an arbitrary type as a meta value.
template <class Type> struct type_c;

/// The held type of an expression.
template <class Expr> using type_of_t = typename Expr::type;

// -----------------------------------------------------------------------------

/// Wraps a constant value of given type as a meta value.
template <class Type, Type value> struct value_c;

/// `auto_c<v>` is shorthand for `value_t<decltype(v), v>`.
template <auto value> using auto_c = value_c<decltype(value), value>;

/// The constant `true` value.
using true_c = value_c<bool, true>;

/// The constant `false` value.
using false_c = value_c<bool, false>;

// -----------------------------------------------------------------------------

/// A ternary conditional expression.
template <class... Exprs> struct if_m;

// -----------------------------------------------------------------------------

/// A multi legged conditional expression.
template <class... Cases> struct switch_m;

/// A conditional leg of a switch expression.
template <class Condition, class Consequent> struct case_c;

/// An unconditional leg of a switch expression.
template <class Consequent> struct default_c;

// -----------------------------------------------------------------------------

/// Applies meta function class to actual arguments.
template <class Function, class... Actuals> struct apply_m;

// -----------------------------------------------------------------------------

/// A primitive meta function template as a non-strict meta function class.
template <template <class... Formals> class Primitive, size_t arity>
struct from_primitive_c;

/// A primitive meta function template as a non-strict meta function template.
template <template <class... Formals> class Primitive,
          size_t arity,
          class... Actuals>
using primitive_c =
    force_c<apply_m<from_primitive_c<Primitive, arity>, Actuals...>>;

// -----------------------------------------------------------------------------

/// A type returning strict trait as a non-strict meta function class.
template <template <class... Formals> class Trait, size_t arity>
struct from_type_trait_c;

/// A type returning strict trait as a non-strict meta function template.
template <template <class... Formals> class Trait,
          size_t arity,
          class... Actuals>
using type_trait_c =
    force_c<apply_m<from_type_trait_c<Trait, arity>, Actuals...>>;

// -----------------------------------------------------------------------------

/// A value returning strict trait as a non-strict meta function class.
template <template <class... Formals> class Trait, size_t arity, class Type>
struct from_value_trait_c;

/// A value returning strict trait as a non-strict meta function template.
template <template <class... Formals> class Trait,
          size_t arity,
          class Type,
          class... Actuals>
using value_trait_c =
    force_c<apply_m<from_value_trait_c<Trait, arity, Type>, Actuals...>>;

// -----------------------------------------------------------------------------

/// A non-strict meta function class as a strict type returning trait.
template <class Function, class... Actuals>
using as_type_trait_t = type_of_t<apply_m<Function, type_c<Actuals>...>>;

/// A non-strict meta function class as a strict value returning trait.
template <class Function, class... Actuals>
inline constexpr auto as_value_trait_v =
    apply_m<Function, type_c<Actuals>...>::value;

// -----------------------------------------------------------------------------

/// A binary meta function class with zero as a variadic meta function
/// template.
template <class Empty, class Concat, class... Exprs> struct nullary_variadic_m;

// -----------------------------------------------------------------------------

/// Holds a sequence.
template <class... Values> struct seq_c;

// -----------------------------------------------------------------------------

/// Single argument meta function class expression.
template <class Formal, class Expr> struct function_c;

/// Multi argument meta function class expression. `fn_c<seq_c<V1, ..., Vn>,
/// Expr>` is equivalent to `function_c<V1, ..., function_c<Vn, Expr> ... >`.
template <class Formals, class Expr> struct fn_c;

// functional.hpp ==============================================================

/// Fixed point of a meta function class.
template <class... Function> struct fix_m;

/// Identity meta function template returns its argument.
template <class... Expr> struct identity_m;

/// Constant meta function template always returns its first argument and
/// ignores its second argument.
template <class... Exprs> struct constant_m;

/// Binary meta function class composition.  `apply_m<compose_m<F, G>, X>` is
/// equivalent to `apply_m<F, apply_m<G, X>>`.
template <class... Functions> struct compose_m;

/// Binary meta function class reverse composition.  `apply_m<pipe_m<F, G>, X>`
/// is equivalent to `apply_m<G, apply_m<F, X>>`.
template <class... Functions> struct pipe_m;

/// Passes given expression through the reverse composition of given meta
/// function classes. `thru_m<X, F1, ..., Fn>` is equivalent to
/// `apply_m<pipes_m<F1, ..., Fn>, X>`.
template <class Expr, class... Functions> struct thru_m;

// -----------------------------------------------------------------------------

/// Variadic meta function class composition.
template <class... Functions>
using composes_m = nullary_variadic_m<identity_m<>, compose_m<>, Functions...>;

/// Variadic meta function class reverse composition.
template <class... Functions>
using pipes_m = nullary_variadic_m<identity_m<>, pipe_m<>, Functions...>;

// arithmetic.hpp ==============================================================

/// Binary arithmetic value addition (`+`).
template <class... Exprs> struct add_m;

/// Binary arithmetic value division (`/`).
template <class... Exprs> struct div_m;

/// Binary arithmetic value modulo (`%`).
template <class... Exprs> struct mod_m;

/// Binary arithmetic value multiplication (`*`).
template <class... Exprs> struct mul_m;

/// Binary arithmetic value subtraction (`-`).
template <class... Exprs> struct sub_m;

/// Unary arithmetic value negation (`-`).
template <class... Expr> struct neg_m;

// -----------------------------------------------------------------------------

// Arithmetic increment value by 1.
template <class... Expr> using inc_m = add_m<value_c<int, 1>, Expr...>;

// Arithmetic decrement value by 1.
template <class... Expr> using dec_m = add_m<value_c<int, -1>, Expr...>;

// -----------------------------------------------------------------------------

/// Variadic arithmetic value addition (`+`).
template <class... Exprs>
using adds_m = nullary_variadic_m<value_c<int, 0>, add_m<>, Exprs...>;

/// Variadic arithmetic value multiplication (`*`).
template <class... Exprs>
using muls_m = nullary_variadic_m<value_c<int, 1>, mul_m<>, Exprs...>;

// comparison.hpp ==============================================================

/// Binary equal to (`==`) value comparison.
template <class... Exprs> struct eq_m;

/// Binary greater than (`>`) value comparison.
template <class... Exprs> struct gt_m;

/// Binary greater than or equal to (`>=`) value comparison.
template <class... Exprs> struct gte_m;

/// Binary less than (`<`) value comparison.
template <class... Exprs> struct lt_m;

/// Binary less than or equal to (`<=`) value comparison.
template <class... Exprs> struct lte_m;

/// Binary not equal to (`!=`) value comparison.
template <class... Exprs> struct neq_m;

// logical.hpp =================================================================

/// Binary logical value conjunction (`&&`).
template <class... Exprs> struct and_m;

/// Binary logical value disjunction (`||`)).
template <class... Exprs> struct or_m;

/// Unary logical value negation (`!`).
template <class... Expr> struct not_m;

// -----------------------------------------------------------------------------

/// Variadic logical value conjunction.
template <class... Exprs>
using ands_m = nullary_variadic_m<true_c, and_m<>, Exprs...>;

/// Variadic logical value disjunction.
template <class... Exprs>
using ors_m = nullary_variadic_m<false_c, or_m<>, Exprs...>;

// type_traits.hpp =============================================================

/// `std::alignment_of` as a non-strict meta function template.
template <class... Expr> struct alignment_of_m;

//

/// `std::is_array` as a non-strict meta function template.
template <class... Expr> struct is_array_m;

/// `std::is_pointer` as a non-strict meta function template.
template <class... Expr> struct is_pointer_m;

//

/// `std::is_same` as a non-strict meta function template.
template <class... Exprs> struct is_same_m;

//

/// `std::remove_all_extents` as a non-strict meta function template.
template <class... Expr> struct remove_all_extents_m;

/// `std::remove_pointer` as a non-strict meta function template.
template <class... Expr> struct remove_pointer_m;

} // namespace lax_v1
