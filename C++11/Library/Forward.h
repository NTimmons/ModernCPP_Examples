#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include<iostream>

namespace ForwardExample
{
	struct A
	{
		A() = default;
		A(const A& o) { std::cout << "copied" << std::endl; }
		A(A&& o) { std::cout << "moved" << std::endl; }
	};

	template <typename T>
	A wrapper(T&& arg)
	{
		return A{ std::forward<T>(arg) };
	}

	void Forward()
	{
		wrapper(A{}); // moved
		A a{};
		wrapper(a); // copied
		wrapper(std::move(a)); // moved

	}
}



//#endif