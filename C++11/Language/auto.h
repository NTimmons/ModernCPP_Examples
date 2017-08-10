#pragma once
//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <vector>

namespace AutoExample_Example
{
	template <typename X, typename Y>
	auto add(X x, Y y) -> decltype(x + y)
	{
		return x + y;
	}

	void Auto()
	{
		//Example 1
		auto a = 3.14; // double
		auto b = 1; // int
		auto& c = b; // int&
		auto d = { 0 }; // std::initializer_list<int>
		auto&& e = 1; // int&&
		auto&& f = b; // int&
		auto g = new auto(123); // int*
		const auto h = 1; // const int

		auto i = 1, j = 2, k = 3; // int, int, int

								  //Error-> auto l = 1, m	= true, n = 1.61; // error -- `l` deduced to be int, `m` is bool
								  //Error-> auto o; // error -- `o` requires initializer

								  //Example 2
		std::vector<int> v = { 1,2,3,4,5,6 };
		std::vector<int>::const_iterator cit0 = v.cbegin();
		// vs.
		auto cit1 = v.cbegin();

		//Example 3
		add(1, 2); // == 3
		add(1, 2.0); // == 3.0
		add(1.5, 1.5); // == 3.0
	}

}

//#endif