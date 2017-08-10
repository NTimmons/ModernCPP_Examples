#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace ConvertingConstructors_Example
{
	//Example One
	struct A 
	{
		A(int) {}
		A(int, int) {}
		A(int, int, int) {}
	};

	void ConvertingConstructorsOne()
	{
		A a{ 0, 0 }; // calls A::A(int, int)
		A b(0, 0); // calls A::A(int, int)
		A c = { 0, 0 }; // calls A::A(int, int)
		A d{ 0, 0, 0 }; // calls A::A(int, int, int)
	}

	//Example Two
	struct B 
	{
		B(int) {}
	};

	void ConvertingConstructorsTwo()
	{
		B a(1.1); // OK
		//Error -> B b{ 1.1 }; // Error narrowing conversion from double to int
	}

	//Example Three
	struct C 
	{
		C(int) {}
		C(int, int) {}
		C(int, int, int) {}
		C(std::initializer_list<int>) {}
	};

	void ConvertingConstructorsThree()
	{
		C a{ 0, 0 }; // calls A::A(std::initializer_list<int>)
		C b(0, 0); // calls A::A(int, int)
		C c = { 0, 0 }; // calls A::A(std::initializer_list<int>)
		C d{ 0, 0, 0 }; // calls A::A(std::initializer_list<int>)
	}

}


//#endif