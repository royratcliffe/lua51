/**
 * This header file carries the `h` extension rather than `hpp` because
 * `devtools::check()` complains about it. The checks do not include that
 * extension as a likely source component. The `h` extension implies inclusion
 * by _either_ C++ or C. Hence the C++ sit within `__cplusplus` condition
 * pragms; C-compiled units skip.
 */

#if __cplusplus
namespace lua {
  class State {
  public:
    State();
    ~State();
  };
}
#endif
