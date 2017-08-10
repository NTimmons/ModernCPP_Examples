#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace StaticAssertions_Example
{

	void StaticAssertions()
	{
		constexpr int x = 0;
		constexpr int y = 1;
		static_assert(x == 0, "x != y");
		static_assert(y == 1, "x != y");
	}

}

//#endif