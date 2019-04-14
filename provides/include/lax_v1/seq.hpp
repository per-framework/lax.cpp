#pragma once

#include "lax_v1/force.hpp"
#include "lax_v1/logical.hpp"
#include "lax_v1/value.hpp"

template <class... Elements> struct lax_v1::Seq::t { using eval = t; };

template <class Sequence>
struct lax_v1::Seq::length_m : force_t<length_m<force_t<Sequence>>> {};
template <class... Elements>
struct lax_v1::Seq::length_m<lax_v1::Seq::t<Elements...>>
    : auto_t<sizeof...(Elements)> {};

template <class Predicate, class Sequence>
struct lax_v1::Seq::any_m : force_t<any_m<Predicate, force_t<Sequence>>> {};
template <class Predicate, class... Elements>
struct lax_v1::Seq::any_m<Predicate, lax_v1::Seq::t<Elements...>>
    : force_t<or_m<apply_m<Predicate, Elements>...>> {};

template <class Function, class Sequence>
struct lax_v1::Seq::map_m
    : force_t<map_m<force_t<Function>, force_t<Sequence>>> {};
template <class Function, class... Elements>
struct lax_v1::Seq::map_m<Function, lax_v1::Seq::t<Elements...>>
    : t<force_t<apply_m<Function, Elements>>...> {};
