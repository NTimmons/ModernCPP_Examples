#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace Nullptr_Example
{
	void foo(int)
	{
	}

	void foo(char*)
	{
	}

	void Nullptr()
	{
		foo(NULL); // error -- ambiguous
		foo(nullptr); // calls foo(char*)
	}
}


//#endif