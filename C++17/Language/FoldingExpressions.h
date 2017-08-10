#pragma once

#ifdef NOT_SUPPORTED_ENABLED

namespace FoldingExpressions_Example
{

	template<typename... Args>
	bool logicalAnd(Args... args)
	{
		// Binary folding.
		return (true && ... && args);
	}

	template<typename... Args>
	auto sum(Args... args)
	{
		// Unary folding.
		return (... + args);
	}

	void FoldingExpressions()
	{
		bool b = true;
		bool& b2 = b;
		logicalAnd(b, b2, true); // == true


		sum(1.0, 2.0f, 3); // == 6.0
	}
}

#endif