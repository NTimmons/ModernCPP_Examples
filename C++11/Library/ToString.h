#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <string>

void ToString()
{
	std::to_string(1.2); // == "1.2"
	std::to_string(123); // == "123"
}

//#endif