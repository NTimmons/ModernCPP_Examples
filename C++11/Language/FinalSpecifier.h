#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace FinalSpecifier_Example
{

	//Example One
	struct A 
	{
		virtual void foo();
	};

	struct B : A 
	{
		virtual void foo() final;
	};

	struct C : B 
	{
		//Error -> virtual void foo(); // error -- declaration of 'foo' overrides a 'final' function
	};


	//Example 2
	struct AA final 
	{
	};

	//ERROR ->
	//struct BB : AA 
	//{ // error -- base 'A' is marked 'final'
	//
	//};

	void FinalSpecifier()
	{

	}
}


//#endif