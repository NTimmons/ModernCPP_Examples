#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace CompileTimeIntegers_Example
{
	template<typename Array, std::size_t... I>
	decltype(auto) a2t_impl(const Array& a, std::integer_sequence<std::size_t, I...>)
	{
		return std::make_tuple(a[I]...);
	}

	template<typename T, std::size_t N, typename Indices = std::make_index_sequence<N>>
	decltype(auto) a2t(const std::array<T, N>& a)
	{
		return a2t_impl(a, Indices());
	}

	void CompileTimeintegers()
	{

	}
}



//#endif