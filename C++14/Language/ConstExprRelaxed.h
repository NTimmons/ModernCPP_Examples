#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace ConstExprRelaxed_Example
{
	constexpr int factorial(int n)
	{
		if (n <= 1)
		{
			return 1;
		}
		else
		{
			return n * factorial(n - 1);
		}
	}

	void ConstExprRelaxed()
	{
		factorial(5); // == 120
	}
}

//#endif