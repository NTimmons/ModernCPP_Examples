#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <chrono>

namespace Chrono_Example
{
	//todo
	//	std::system_clock
	//	std::steady_clock
	//	std::high_resolution_clock
	//	std::time_point
	//	std::treat_as_floating_point
	//	std::duration_values
	//	std::chrono::nanoseconds	//duration type with Period std::nano
	//	std::chrono::microseconds	//duration type with Period std::micro
	//	std::chrono::milliseconds	//duration type with Period std::milli
	//	std::chrono::seconds		//duration type with Period std::ratio<1>
	//	std::chrono::minutes		//duration type with Period std::ratio<60>
	//	std::chrono::hours			//duration type with Period std::ratio<3600>
	//	std::common_type<std::chrono::duration>

	void Chrono()
	{
		std::chrono::time_point<std::chrono::system_clock> start;
		std::chrono::time_point<std::chrono::system_clock> end;

		start	= std::chrono::system_clock::now();
		end		= std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_seconds = end - start;

		elapsed_seconds.count(); // t number of seconds, represented as a `double`
	}
}



//#endif