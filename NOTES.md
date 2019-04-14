Apparently VC++ 2017 is not quite ready for

```c++
template <auto v> struct value_c {
  using eval = value_c;
  using type = decltype(v);
  static constexpr auto value = v;
};
```

because `decltype(v)` does not always seem to give the expected type.
