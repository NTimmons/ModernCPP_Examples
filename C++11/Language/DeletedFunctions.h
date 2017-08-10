#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace DeletedFunction_Example
{
	class A 
	{
		int x;

	public:
		A(int x) : x(x) {};
		A(const A&) = delete;
		A& operator=(const A&) = delete;
	};

	void DeletedFunction()
	{
		A x{ 123 };
		// Error -> A y = x; // error -- call to deleted copy constructor
		// Error -> y = x; // error -- operator= deleted
	}
}


//#endif