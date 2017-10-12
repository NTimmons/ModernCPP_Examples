#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <future>

namespace Async_Example
{

	int asyncThread(int _value)
	{
		return _value + 1;
	}

	void Async()
	{
		//1. Simple Async thread. Thread creation returns a future for the return type. This is the same as a future on a thread which
		//   is set to validate on thread finish.
		int inValue = 10;
		std::future<int> handle_1 = std::async(std::launch::async, asyncThread, inValue);
		int threadReturn = handle_1.get();
		std::cout << "Result of thread work is: " << threadReturn << ".\n";

		std::cout << "Async Example finished.\n";

		//2. Deferred Async thread. Thread creation returns a future for the return type. This thread is not executed until the future value is requested
		inValue = 10;
		std::future<int> handle_2 = std::async(std::launch::deferred, asyncThread, inValue);
		threadReturn = handle_2.get();
		std::cout << "Result of deferred thread work is: " << threadReturn << ".\n";

		std::cout << "Async Example finished.\n";
	}
}



//#endif