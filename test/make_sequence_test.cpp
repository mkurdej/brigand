#include <brigand/sequences/make_sequence.hpp>
#include <brigand/functions/arithmetic/prev.hpp>
#include <brigand/types/integer.hpp>
#include <brigand/adapted/integral_list.hpp>

static_assert(std::is_same<brigand::as_integral_list<brigand::make_sequence<brigand::uint32_t<0>, 3>>,
  brigand::integral_list<std::uint32_t, 0, 1, 2>>::value, "invalid make_sequence result");
static_assert(std::is_same<brigand::as_integral_list<brigand::make_sequence<brigand::int32_t<2>, 4, brigand::prev>>,
  brigand::integral_list<std::int32_t, 2, 1, 0, -1>>::value, "invalid make_sequence result");
static_assert(std::is_same<brigand::as_integral_list<brigand::make_sequence<brigand::uint32_t<0>, 10>>,
  brigand::integral_list<std::uint32_t, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9>>::value, "invalid make_sequence result");
