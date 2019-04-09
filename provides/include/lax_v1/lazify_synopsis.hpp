#pragma once

namespace lax_v1 {

template <template <class... Parameters> class Function, class... Arguments>
struct lazify_t;

template <class Type, template <class... Parameters> class Function,
          class... Arguments>
struct lazify_v;

} // namespace lax_v1
