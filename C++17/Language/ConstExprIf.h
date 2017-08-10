#pragma once
#include <type_traits>

#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace ConstExprIf_Example
{
	template <typename T>
	constexpr bool isIntegral()
	{
		if constexpr (std::is_integral<T>::value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void ConstExprIf()
	{
		static_assert(isIntegral<int>() == true);
		static_assert(isIntegral<char>() == true);
		static_assert(isIntegral<double>() == false);
		struct S {};
		static_assert(isIntegral<S>() == false);
	}
}

#endif