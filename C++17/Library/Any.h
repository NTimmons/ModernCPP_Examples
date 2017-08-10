#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <any>

namespace Any_Example
{
	void Any()
	{
		std::any x{ 5 };
		x.has_value(); // == true
		std::any_cast<int>(x); // == 5
		std::any_cast<int&>(x) = 10;
		std::any_cast<int>(x); // == 10
	}
}

//#endif