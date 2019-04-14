# [≡](#contents) [Lax.C++](#) [![Build Status](https://travis-ci.org/per-framework/lax.cpp.svg?branch=v1)](https://travis-ci.org/per-framework/lax.cpp)

Non-strict template metaprogramming primitives for C++.

See [`synopsis.hpp`](provides/include/lax_v1/synopsis.hpp) for the API.

## <a id="contents"></a> [≡](#contents) [Contents](#contents)

- [Legend](#legend)
- [Glossary](#glossary)
  - [Currying](#currying)
  - [Meta expression](#meta-expression)
  - [Meta function](#meta-function)
  - [Meta value](#meta-value)
  - [Non-strict evaluation](#non-strict-evaluation)
- [Motivation](#motivation)
- [References](#references)

## <a id="legend"></a> [≡](#contents) [Legend](#legend)

- `_m` [meta expression](#meta-expression) template
- `_c` [meta value](#meta-value) or meta value template
- `_p` primitive (internal type alias or meta expression template or class)
- `_t` type alias (from C++11)
- `_v` value constexpr (from C++17)

## <a id="glossary"></a> [≡](#contents) [Glossary](#glossary)

### <a id="currying"></a> [≡](#contents) [Currying](#currying)

### <a id="meta-expression"></a> [≡](#contents) [Meta expression](#meta-expression)

A lax meta expression is a type that is a subtype of a single
[meta value](#meta-value) and includes no other members aside from those defined
by that meta value.

```c++
using a_meta_expression = add_m<auto_c<1>, auto_c<2>>;
struct also_a_meta_expression : a_meta_expression {};
```

Lax meta expression templates are typically [curried](#curried) and produce
[meta functions](#meta-function) when partially applied.

### <a id="meta-function"></a> [≡](#contents) [Meta function](#meta-function)

A lax meta function is a [meta value](#meta-value) that has a static `arity`
constant and an inner type template `template_m` that takes at least `arity`
types as arguments and whose result is a [meta expression](#meta-expression).

```c++
struct a_meta_function_c {
  using eval = a_meta_function_c;
  static constexpr size_t arity = N;
  template <class Actual_1, ..., class Actual_N>
  struct template_m : a_meta_expression {};
};
```

Lax higher-order meta functions take meta functions as arguments and use them
via the `apply_m` [meta expression template](#meta-expression-template). Note
that `template_m` need not support [currying](#currying) like
[meta expression templates](#meta-expression-template), because `apply_m` takes
care of that.

### <a id="meta-value"></a> [≡](#contents) [Meta value](#meta-value)

A lax meta value is a [meta expression](#meta-expression) whose inner `eval`
type is an alias for the meta expression itself.

```c++
struct a_meta_value_c {
  using eval = a_meta_value_c;
  // and additional members depending on value
};
```

Meta values also typically include additional static constants, types, or type
templates.

### <a id="non-strict-evaluation"></a> [≡](#contents) [Non-strict evaluation](#non-strict-evaluation)

## <a id="motivation"></a> [≡](#contents) [Motivation](#motivation)

## <a id="references"></a> [≡](#contents) [References](#references)
