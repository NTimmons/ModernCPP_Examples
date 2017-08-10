#pragma once
#include <memory>

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace LambdaCaptureInit_Example
{

	int factory(int i)
	{
		return i * 10;
	}

	void LambdaCaptureInit()
	{
		//Example one
		{
			auto f = [x = factory(2)]{ return x; }; // returns 20

			auto generator = [x = 0]() mutable
			{
				// this would not compile without 'mutable' as we are modifying x on each call
				return x++;
			};
			auto a = generator(); // == 0
			auto b = generator(); // == 1
			auto c = generator(); // == 2
		}

		//Example two
		{
			auto p = std::make_unique<int>(1);

			//Produces error
			//auto task1 = [=] { *p = 5; }; // ERROR: std::unique_ptr cannot be copied
										  // vs.
			auto task2 = [p = std::move(p)]{ *p = 5; }; // OK: p is move-constructed into the closure object
														// the original p is empty after task2 is created
		}

		//Example three
		{
			auto x = 1;
			auto f = [&r = x, x = x * 10]
			{
				++r;
				return r + x;
			};

			f(); // sets x to 2 and returns 12
		}
	}

}

//#endif