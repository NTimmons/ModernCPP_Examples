#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <tuple>

namespace Apply_Example
{
	auto applyAdd = [](int x, int y)
	{
		return x + y;
	};

	void Apply()
	{
		std::apply(applyAdd, std::make_tuple(1, 2)); // == 3
	}
}

//#endif