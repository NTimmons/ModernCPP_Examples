#pragma once

#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <numeric>
namespace CommonDenominators_Example
{
	void CommonDenominators()
	{
		int lowestCommon	= std::lcd(200, 100);
		int greatestCommon	= std::gcd(200, 20);
	}
}

//#endif