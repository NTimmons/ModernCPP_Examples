#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace TypeTraits_Example
{
	//todo
	//http://en.cppreference.com/w/cpp/header/type_traits

	void TypeTraits()
	{
		static_assert(std::is_integral<int>::value == 1);
		static_assert(std::is_same<int, int>::value == 1);
		static_assert(std::is_same<std::conditional<true, int, double>::type, int>::value == 1);
	}

}


//#endif