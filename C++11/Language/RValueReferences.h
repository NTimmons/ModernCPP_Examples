#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace RValueReference_Example
{
	void RValueReference()
	{
		int x = 0;					// `x` is an lvalue of type `int`
		int& xl = x;				// `xl` is an lvalue of type `int&`
		//Error -> int&& xr = x;	// compiler error -- `x` is an lvalue
		int&& xr2 = 0;				// `xr2` is an lvalue of type `int&&`
		auto& al = x;				// `al` is an lvalue of type `int&`
		auto&& al2 = x;				// `al2` is an lvalue of type `int&`
		auto&& ar = 0;				// `ar` is an lvalue of type `int&&`
	}
}

//#endif