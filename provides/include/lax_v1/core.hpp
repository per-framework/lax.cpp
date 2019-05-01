#pragma once

#include "lax_v1/synopsis.hpp"

#include <type_traits>

//

namespace lax_v1 {
class apply_private {
  template <class Function, class... Actuals> friend struct apply_m;
  template <class... Actuals> struct t { using eval = t; };
  template <class Prefix, class Suffix> struct concat;
  template <size_t n, class... Actuals> struct take_n;
  template <size_t n, class... Actuals> struct drop_n;
  template <class Function, class Actuals> struct apply_exact;
  template <class Function, class Actuals> struct apply_rest;
  template <class Function, class... Actuals> struct apply;
};

template <class Function, class... BoundActuals> struct closure_c {
  using eval = closure_c;
  static constexpr size_t arity = Function::arity - sizeof...(BoundActuals);
  template <class... Actuals>
  struct template_m
      : force_c<typename Function::template template_m<BoundActuals...,
                                                       Actuals...>> {};
};
} // namespace lax_v1

//

template <class WHNF> struct lax_v1::force_deep_from_whnf_m : WHNF {};

template <class Type>
struct lax_v1::force_deep_from_whnf_m<lax_v1::type_c<Type>> : type_c<Type> {};

template <class Formals, class Expr>
struct lax_v1::force_deep_from_whnf_m<lax_v1::function_c<Formals, Expr>>
    : function_c<Formals, Expr> {};

template <class Function, class... BoundActuals>
struct lax_v1::force_deep_from_whnf_m<
    lax_v1::closure_c<Function, BoundActuals...>>
    : closure_c<Function, BoundActuals...> {};

template <template <class... Formals> class Constructor, class... Actuals>
struct lax_v1::force_deep_from_whnf_m<Constructor<Actuals...>>
    : Constructor<force_deep_c<Actuals>...> {};

//

template <class Type> struct lax_v1::type_c {
  using eval = type_c;
  using type = Type;
};

//

template <class Type, Type value>
struct lax_v1::value_c : std::integral_constant<Type, value> {
  using eval = value_c;
};

//

namespace lax_v1 {
template <class Cond, class Then, class Else>
struct if_p : force_c<if_p<force_c<Cond>, Then, Else>> {};
template <class Then, class Else>
struct if_p<true_c, Then, Else> : force_c<Then> {};
template <class Then, class Else>
struct if_p<false_c, Then, Else> : force_c<Else> {};
} // namespace lax_v1

template <class... Exprs>
struct lax_v1::if_m : primitive_c<if_p, 3, Exprs...> {};

//

template <class Consequent>
struct lax_v1::switch_m<lax_v1::default_c<Consequent>> : force_c<Consequent> {};

template <class Condition, class Consequent, class... Cases>
struct lax_v1::switch_m<lax_v1::case_c<Condition, Consequent>, Cases...>
    : force_c<if_p<Condition, Consequent, switch_m<Cases...>>> {};

template <class Condition, class Consequent> struct lax_v1::case_c {
  using eval = case_c;
};

template <class Consequent> struct lax_v1::default_c {
  using eval = default_c;
};

//

template <class Function, class... Actuals>
struct lax_v1::apply_m
    : force_c<if_p<value_c<bool, (sizeof...(Actuals) < Function::arity)>,
                   closure_c<Function, Actuals...>,
                   apply_private::apply<Function, Actuals...>>> {};

template <class Function>
struct lax_v1::apply_m<Function> : force_c<Function> {};

//

template <template <class... Formals> class Primitive, size_t arity_>
struct lax_v1::from_primitive_c {
  using eval = from_primitive_c;
  static constexpr size_t arity = arity_;
  template <class... Actuals>
  struct template_m : force_c<Primitive<Actuals...>> {};
};

//

template <template <class... Formals> class Trait, size_t arity_>
struct lax_v1::from_type_trait_c {
  using eval = from_type_trait_c;
  static constexpr size_t arity = arity_;
  template <class... Actuals>
  struct template_m : type_c<type_of_t<Trait<type_of_t<Actuals>...>>> {};
};

//

template <template <class... Formals> class Trait, size_t arity_, class Type>
struct lax_v1::from_value_trait_c {
  using eval = from_value_trait_c;
  static constexpr size_t arity = arity_;
  template <class... Actuals>
  struct template_m : value_c<Type, Trait<type_of_t<Actuals>...>::value> {};
};

//

template <class... Exprs> struct lax_v1::seq_c { using eval = seq_c; };

//

template <class... Prefix, class... Suffix>
struct lax_v1::apply_private::concat<lax_v1::apply_private::t<Prefix...>,
                                     lax_v1::apply_private::t<Suffix...>>
    : t<Prefix..., Suffix...> {};

template <class... Actuals>
struct lax_v1::apply_private::take_n<0, Actuals...> : t<> {};

template <size_t n, class Actual, class... Actuals>
struct lax_v1::apply_private::take_n<n, Actual, Actuals...>
    : force_c<concat<t<Actual>, force_c<take_n<n - 1, Actuals...>>>> {};

template <class... Actuals>
struct lax_v1::apply_private::drop_n<0, Actuals...> : t<Actuals...> {};

template <size_t n, class Actual, class... Actuals>
struct lax_v1::apply_private::drop_n<n, Actual, Actuals...>
    : force_c<drop_n<n - 1, Actuals...>> {};

template <class Function, class... Actuals>
struct lax_v1::apply_private::apply_exact<Function,
                                          lax_v1::apply_private::t<Actuals...>>
    : force_c<typename Function::template template_m<Actuals...>> {};

template <class Function, class Actual, class... Actuals>
struct lax_v1::apply_private::
    apply_rest<Function, lax_v1::apply_private::t<Actual, Actuals...>>
    : force_c<apply_m<Function, Actual, Actuals...>> {};

template <class Function>
struct lax_v1::apply_private::apply_rest<Function, lax_v1::apply_private::t<>>
    : force_c<Function> {};

template <class Function, class... Actuals>
struct lax_v1::apply_private::apply
    : force_c<apply_rest<
          apply_exact<Function, force_c<take_n<Function::arity, Actuals...>>>,
          force_c<drop_n<Function::arity, Actuals...>>>> {};

//

template <class Empty, class Concat>
struct lax_v1::nullary_variadic_m<Empty, Concat> : force_c<Empty> {};

template <class Empty, class Concat, class Expr>
struct lax_v1::nullary_variadic_m<Empty, Concat, Expr> : force_c<Expr> {};

template <class Empty, class Concat, class Expr1, class Expr2, class... Exprs>
struct lax_v1::nullary_variadic_m<Empty, Concat, Expr1, Expr2, Exprs...>
    : force_c<apply_m<Concat,
                      Expr1,
                      nullary_variadic_m<Empty, Concat, Expr2, Exprs...>>> {};

//

namespace lax_v1 {
class function_private {
  template <class Formal, class Expr> friend struct function_c;
  template <class Formal, class Actual, class Expr>
  struct subst_m : type_c<Expr> {};
  template <class Formal, class Actual, class Expr>
  using subst_t = type_of_t<subst_m<Formal, Actual, Expr>>;
};
} // namespace lax_v1

template <class Formal, class Expr> struct lax_v1::function_c {
  using eval = function_c;
  static constexpr size_t arity = 1;
  template <class Actual>
  struct template_m : function_private::subst_t<Formal, Actual, Expr> {};
};

template <class Formal1, class Formal2, class... Formals, class Expr>
struct lax_v1::fn_c<lax_v1::seq_c<Formal1, Formal2, Formals...>, Expr>
    : function_c<Formal1, force_c<fn_c<seq_c<Formal2, Formals...>, Expr>>> {};

template <class Formal, class Expr>
struct lax_v1::fn_c<lax_v1::seq_c<Formal>, Expr> : function_c<Formal, Expr> {};

//

template <class Formal, class Actual>
struct lax_v1::function_private::subst_m<Formal, Actual, Formal>
    : type_c<Actual> {};

template <class Formal, class Actual, class Expr>
struct lax_v1::function_private::
    subst_m<Formal, Actual, lax_v1::function_c<Formal, Expr>>
    : type_c<function_c<Formal, Expr>> {};

template <class Formal,
          class Actual,
          template <class... Formals>
          class Function,
          class... Exprs>
struct lax_v1::function_private::subst_m<Formal, Actual, Function<Exprs...>>
    : type_c<Function<subst_t<Formal, Actual, Exprs>...>> {};

template <class Formal, class Actual, class ReturnType, class... ParamTypes>
struct lax_v1::function_private::
    subst_m<Formal, Actual, ReturnType(ParamTypes...)>
    : type_c<subst_t<Formal, Actual, ReturnType>(
          subst_t<Formal, Actual, ParamTypes>...)> {};
