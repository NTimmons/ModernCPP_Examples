#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <algorithm>
namespace Clamp_Example
{
	bool cmpFunction(const int &a, const int &b)
	{
		return a < b;
	}

	void Clamp()
	{
		int input = 300;
		int val = std::clamp(input, 0, 255 );
		std::cout << "Clamped value of " << input << " is -> " << val << "\n";

		val = std::clamp(input, 0, 255, cmpFunction);
		std::cout << "Clamped value of " << input << " is -> " << val << "\n";
	}
}

//#endif