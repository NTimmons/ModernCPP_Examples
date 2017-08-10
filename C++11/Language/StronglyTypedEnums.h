#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace StronglyTypedEnums_Example
{
	void StronglyTypedEnums()
	{
		// Specifying underlying type as `unsigned int`
		enum class Color : unsigned int { Red = 0xff0000, Green = 0xff00, Blue = 0xff };
		// `Red`/`Green` in `Alert` don't conflict with `Color`
		enum class Alert : bool { Red, Green };
		Color c = Color::Red;
	}
}

//#endif