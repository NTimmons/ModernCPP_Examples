#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <utility>
#include <iostream>
namespace StructuredBindings_Example
{
	using Coordinate = std::pair<int, int>;
	Coordinate origin()
	{
		return Coordinate{ 0, 0 };
	}

	void StructuredBindings()
	{
		const auto[x, y] = origin();
		x; // == 0
		y; // == 0
	}
}

//#endif