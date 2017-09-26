#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <algorithm>

#include <iostream>
#include <random>
#include <string>

namespace Sampling_Example
{
	void  Sampling()
	{
		std::string input = "Hello this is a test";
		std::string output;
		std::mt19937 randomDevice(std::random_device{}());

		std::sample(input.begin(), input.end(), std::back_inserter(output), 10, randomDevice);
		std::cout << "A selection of ten characters from the submitted string: " << input << " -> " << output << '\n';
	}
}



//#endif