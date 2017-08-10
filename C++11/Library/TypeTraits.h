#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

void TypeTraits()
{
	static_assert(std::is_integral<int>::value == 1);
	static_assert(std::is_same<int, int>::value == 1);
	static_assert(std::is_same<std::conditional<true, int, double>::type, int>::value == 1);
}

//#endif