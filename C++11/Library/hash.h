#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <iostream>
#include <functional>

namespace Hash_Example
{
	void Hash()
	{
		std::size_t h1 = std::hash<std::string>{}("Some String");
		std::cout << h1 << "\n";
	}
}


//#endif