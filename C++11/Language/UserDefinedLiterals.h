#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <string>

namespace UserDefinedLiterals_Example
{
	long long operator "" _celsius(unsigned long long tempCelsius)
	{
		return std::llround(tempCelsius * 1.8 + 32);
	}

	void UserDefinedLiteralsOne()
	{
		// `unsigned long long` parameter required for integer literal.
		24_celsius; // == 75
	}

	// `const char*` and `std::size_t` required as parameters.
	int operator "" _int(const char* str, std::size_t)
	{
		return std::stoi(str);
	}
	void UserDefinedLiteralsTwo()
	{
		// `unsigned long long` parameter required for integer literal.
		"123"_int; // == 123, with type `in
	}
}






//#endif