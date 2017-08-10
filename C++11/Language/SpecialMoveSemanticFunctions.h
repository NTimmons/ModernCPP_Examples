#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <utility>

namespace SpecialMoveSemanticFunctions_Example
{
	struct A
	{
		std::string s;
		A() : s("test") {}
		A(const A& o) : s(o.s) {}
		A(A&& o) : s(std::move(o.s)) {}
		A& operator=(A&& o)
		{
			s = std::move(o.s);
			return *this;
		}
	};

	A f(A a)
	{
		return a;
	}

	void SpecialMoveSemanticFunctions()
	{
		A a1 = f(A{}); // move-constructed from rvalue temporary
		A a2 = std::move(a1); // move-constructed using std::move
		A a3 = A{};
		a2 = std::move(a3); // move-assignment using std::move
		a1 = f(A{}); // move-assignment from rvalue temporary
	}

}

//#endif