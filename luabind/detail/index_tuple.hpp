#ifndef LUABIND_INDEX_TUPLE_HPP
#define LUABIND_INDEX_TUPLE_HPP

namespace luabind { namespace detail {

template<int...> struct index_tuple{};

template<typename IndexTuple, int I, int S>
struct make_indices_impl
{};

template<int... Indices, int I, int S>
struct make_indices_impl<index_tuple<Indices...>, I, S>
{
  typedef typename make_indices_impl<index_tuple<Indices..., I>, I + 1, S>::type type;
};

template<int... Indices, int S>
struct make_indices_impl<index_tuple<Indices...>, S, S>
{
  typedef index_tuple<Indices...> type;
};


template<typename... Types>
struct make_index_tuple
{
  typedef typename make_indices_impl<index_tuple<>, 0, sizeof...(Types)>::type type;
};

} }

#endif
