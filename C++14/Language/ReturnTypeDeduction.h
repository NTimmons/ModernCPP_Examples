#pragma once

#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace ReturnTypeDeduction_Example
{

// Deduce return type as `int`.
auto f(int i)
{
	return i;
}

template <typename T>
auto& f(T& t)
{
	return t;
}

void ReturnTypeDeduction()
{
	// Returns a reference to a deduced type.
	auto g	= [](auto& x) -> auto& { return f(x); };
	int y	= 123;
	int& z	= g(y); // reference to `y`
}

}

#endif