#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <variant>
namespace Variant_Example
{
	void Variant()
	{
		std::variant<int, double> v{ 12 };
		std::get<int>(v); // == 12
		std::get<0>(v); // == 12
		v = 12.0;
		std::get<double>(v); // == 12.0
		std::get<1>(v); // == 12.0
	}
}

//#endif