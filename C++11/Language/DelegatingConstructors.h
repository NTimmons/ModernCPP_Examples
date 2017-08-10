#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace DelegatingConstructors_Example
{

	void DelegatingConstructors()
	{
		struct Foo 
		{
			int foo;
			Foo(int foo) : foo(foo) {}
			Foo() : Foo(0) {}
		};

		Foo foo{};
		foo.foo; // == 0
	}
}

//#endif