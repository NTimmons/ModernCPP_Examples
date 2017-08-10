#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <chrono>
using namespace std::chrono_literals;

namespace UserLiterals
{

	void UserLiterals()
	{
		auto day = 24h;
		day.count(); // == 24
		std::chrono::duration_cast<std::chrono::minutes>(day).count(); // == 1440
	}

}


//#endif