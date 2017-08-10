#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <chrono>

void Chrono()
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	// Some computations...
	end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;

	elapsed_seconds.count(); // t number of seconds, represented as a `double`
}

//#endif