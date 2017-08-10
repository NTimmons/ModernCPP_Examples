#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <optional>

namespace Optional_Example
{
	std::optional<std::string> create(bool b)
	{
		if (b)
		{
			return "Godzilla";
		}
		else
		{
			return {};
		}
	}

	void Optional()
	{
		create(false).value_or("empty");	// == "empty"
		create(true).value();				// == "Godzilla"
											// optional-returning factory functions are usable as conditions of while and if
		if (auto str = create(true))
		{
			// ...
		}
	}
}

//#endif