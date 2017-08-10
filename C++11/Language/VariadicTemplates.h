#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace VariadicTemplates_Example
{
	template <typename... T>
	struct arity
	{
		constexpr static int value = sizeof...(T);
	};

	void VariadicTemplates()
	{

		static_assert(arity<>::value == 0);
		static_assert(arity<char, short, int>::value == 3);
	}
}

//#endif