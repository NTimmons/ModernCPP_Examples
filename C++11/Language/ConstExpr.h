#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace ConstExpr_Example
{
	constexpr int square(int x) 
	{
		return x * x;
	}

	int square2(int x) 
	{
		return x * x;
	}

	void ConstExprOne()
	{
		int a = square(2);  // mov DWORD PTR [rbp-4], 4

		int b = square2(2); // mov edi, 2
							// call square2(int)
							// mov DWORD PTR [rbp-8], eax
	}

	void ConstExprTwo()
	{
		const int x = 123;
		//Error -> constexpr const int& y = x; // error -- constexpr variable `y` must be initialized by a constant expression
	}

	struct Complex 
	{
		constexpr Complex(double r, double i) : re(r), im(i) { }
		constexpr double real() { return re; }
		constexpr double imag() { return im; }

	private:
		double re;
		double im;
	};

	void ConstExprThree()
	{
		constexpr Complex I(0, 1);
	}
}


//#endif