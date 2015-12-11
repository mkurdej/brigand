/*==================================================================================================
  Copyright (c) 2015 Edouard Alligand and Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

#include <brigand/sequences/append.hpp>
#include <brigand/sequences/at.hpp>
#include <brigand/sequences/size.hpp>
#include <brigand/types/integer.hpp>

#include <utility>

namespace brigand
{
namespace detail
{

template <class Seq, class Count, class Indices>
struct reverse_elements;

template <template <class...> class Seq, class... U, class Count, std::size_t... I>
struct reverse_elements<Seq<U...>, Count, std::index_sequence<I...>>
{
    static const std::size_t last_index = Count::value - 1u;

    using list_to_reverse = Seq<U...>;

    using type = Seq< //
        brigand::at<  //
            list_to_reverse,
            brigand::size_t<last_index - I>, //
            >...                             //
        >;
};

//template <template <class...> class Seq, class T0>
//struct reverse_elements<Seq, T0>
//{
//    using type = Seq<T0>;
//};

template <class Seq, class Count = brigand::size<Seq>>
struct reverse_impl;

template <template <class...> class Seq, class... U, class Count>
struct reverse_impl<Seq<U...>, Count>
{
    using type = typename reverse_elements<Seq<U...>, Count, std::index_sequence_for<U...>>::type;
};

template <template <class...> class Seq, class... U>
struct reverse_impl<Seq<U...>, brigand::size_t<0>>
{
    using type = Seq<U...>;
};

} // namespace detail

namespace lazy
{

    template <typename Seq>
    using reverse = typename detail::reverse_impl<Seq>;

}

    template <typename Seq>
    using reverse = typename detail::reverse_impl<Seq>::type;

}
