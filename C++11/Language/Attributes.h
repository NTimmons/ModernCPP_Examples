#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace Attribute_Example
{

	// `noreturn` attribute indicates `f` doesn't return.
	[[noreturn]] void f() 
	{
		throw "error";
	}

	void Attributes()
	{

	}
}


//#endif