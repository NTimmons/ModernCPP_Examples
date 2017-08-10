#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <array>

void Array()
{
	std::array<int, 3> a = { 2, 1, 3 };
	std::sort(a.begin(), a.end()); // a == { 1, 2, 3 }
	for (int& x : a) x *= 2; // a == { 2, 4, 6 }
}

//#endif