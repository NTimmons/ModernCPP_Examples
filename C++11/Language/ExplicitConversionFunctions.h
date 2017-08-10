#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace ExplicitConversionFunction_Example
{
	struct A 
	{
		operator bool() const { return true; }
	};

	struct B 
	{
		explicit operator bool() const { return true; }
	};

	void ExplicitConversionFunction()
	{
		A a{};
		if (a); // OK calls A::operator bool()
		bool ba = a; // OK copy-initialization selects A::operator bool()

		B b{};
		if (b); // OK calls B::operator bool()
		//Error -> bool bb = b; // error copy-initialization does not consider B::operator bool()
	}
}


//#endif