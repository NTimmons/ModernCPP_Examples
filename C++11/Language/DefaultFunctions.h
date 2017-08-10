#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace DefaultFunctions_Example
{
	//Example One
	struct A 
	{
		A() = default;
		A(int x) : x(x) {}
		int x{ 1 };
	};

	//Example Two
	struct B 
	{
		B() : x(1) {};
		int x;
	};

	struct C : B 
	{
		// Calls B::B
		C() = default;
	};

	void DefaultFunctions()
	{
		//Example One
		A a{}; // a.x == 1
		A a2{ 123 }; // a.x == 123

		//Example Two
	}
}


//#endif