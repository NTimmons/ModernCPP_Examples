#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace ExplicitVirtualOverrides_Example
{
	struct A 
	{
		virtual void foo() {};
		void bar() {};
	};

	struct B : A 
	{
		void foo() override {}; // correct -- B::foo overrides A::foo
		//Error -> void bar() override; // error -- A::bar is not virtual
		//Error -> void baz() override; // error -- B::baz does not override A::baz
	};


	void ExplicitVirtualOverrides()
	{

	}
}


//#endif