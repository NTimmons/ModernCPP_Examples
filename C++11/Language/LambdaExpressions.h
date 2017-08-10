#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace LambdaExpression_Example
{
	void LambdaExpressionOne()
	{
		//Example 1
		int x = 1;

		auto getX = [=] { return x; };
		getX(); // == 1

		auto addX = [=](int y) { return x + y; };
		addX(1); // == 2

		auto getXRef = [&]() -> int& { return x; };
		getXRef(); // int& to `x`
	}

	void LambdaExpressionTwo()
	{
		//Example 2
		int x = 1;

		auto f1 = [&x] { x = 2; }; // OK: x is a reference and modifies the original

		//Error -> auto f2 = [x] { x = 2; }; // ERROR: the lambda can only perform const-operations on the captured value
								  // vs.
		auto f3 = [x]() mutable { x = 2; }; // OK: the lambda can perform any operations on the captured value
	}
}

//#endif