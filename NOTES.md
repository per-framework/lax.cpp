Apparently VC++ 2017 is not quite ready for

```c++
template <auto v> struct value_t {
  using eval = value_t;
  using type = decltype(v);
  static constexpr auto value = v;
};
```

because `decltype(v)` does not always seem to give the expected type.
