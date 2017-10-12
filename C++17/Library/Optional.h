#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <optional>
#include <iostream>

namespace Optional_Example
{
	std::optional<std::string> create(bool _in)
	{
		if (_in)
		{
			return "Some String";
		}
		else
		{
			return {};
		}
	}

	void Optional()
	{
		create(false).value_or("empty");	// returns "empty" as create returns an empty optional
		create(true).value();				// returns "Some String" as the optional object returned has this value
		
		// the result of the optional object can be tested not empty in if/while loops
		if (auto str = create(true))
		{
			// ...
		}
	}
}

//#endif