#pragma once

#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <charconv>

namespace StringConversion_Example
{
	void StringConversion()
	{
		std::string someString = "10.0";
		double valueOut;

		std::from_chars_result charResult = std::from_chars(someString.begin(), someString.end(), valueOut);

	}
}

#endif