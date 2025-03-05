#include <algorithm>  // for std::copy_n
#include <cstddef>    // for std::size_t

template <std::size_t N>
struct crazy_string_literal_type
{
  char value[N];
  constexpr crazy_string_literal_type(char const (&str)[N])
  {
    std::copy_n(str,N,value);
  }
};
template <crazy_string_literal_type c>
constexpr auto operator""_hmmm() { return c; }

auto cool = "This is some text."_hmmm;
