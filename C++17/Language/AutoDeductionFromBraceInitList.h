#pragma once

#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace AutoDeductionFromBraceInitList_Example
{
	void AutoDeductionFromBraceInitList()
	{
		auto x1{ 1, 2, 3 }; // error: not a single element
		auto x2 = { 1, 2, 3 }; // decltype(x2) is std::initializer_list<int>
		auto x3{ 3 }; // decltype(x3) is int
		auto x4{ 3.0 }; // decltype(x4) is double
	}
}

#endif