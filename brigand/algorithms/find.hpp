/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/algorithms/detail/find.hpp>
#include <brigand/algorithms/detail/non_null.hpp>
#include <brigand/algorithms/reverse.hpp>
#include <brigand/types/bool.hpp>
#include <brigand/sequences/list.hpp>

namespace brigand
{
namespace lazy
{

    // find uses Predicate, it's very effective
    template<typename Sequence, typename Predicate = detail::non_null>
    using find = typename detail::find_if_impl<Predicate, Sequence>;

}

// find uses Predicate, it's very effective
template<typename Sequence, typename Predicate = detail::non_null>
using find = typename ::brigand::lazy::find<Sequence, Predicate>::type;

namespace lazy
{

    // reverse_find uses reverse and find :o
    template<typename Sequence, typename Predicate = detail::non_null>
    using reverse_find = ::brigand::lazy::reverse< ::brigand::find< brigand::reverse<Sequence>, Predicate> >;

}

template <typename Sequence, typename Predicate = detail::non_null>
using reverse_find = typename ::brigand::lazy::reverse_find<Sequence, Predicate>::type;


// Utility meta-function to check if nothing was found
template<typename Sequence, typename Predicate = detail::non_null>
using not_found = typename std::is_same<find<Sequence, Predicate>, empty_sequence>::type;

// Utility meta-function to check if something was found
// Note: MSVC doesn't like the factoring with not found
template<typename Sequence, typename Predicate = detail::non_null>
using found = bool_<!std::is_same<find<Sequence, Predicate>, empty_sequence>::value>;
}
