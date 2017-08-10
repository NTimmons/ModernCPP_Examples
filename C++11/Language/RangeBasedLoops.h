#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <array>

namespace CompileTimeIntegers_Example
{
	void RangeBasedLoops()
	{
		//Example One
		std::array<int, 5> a{ 1, 2, 3, 4, 5 };
		for (int& x : a) x *= 2;
		// a == { 2, 4, 6, 8, 10 }

		//Example Two
		std::array<int, 5> b{ 1, 2, 3, 4, 5 };
		for (int x : b) x *= 2;
		// a == { 1, 2, 3, 4, 5 }
	}
}

//#endif