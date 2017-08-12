#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <thread>
#include <iostream>

namespace Thread_Example
{
	void SimpleThread()
	{
		// This is a simple function to run on the thread.
	}

	void SingleVariable(int _varOne)
	{
		// This is a simple function that takes one variable to run on the thread.
		std::cout << "Single Variable (int): " << _varOne << "\n";
	}

	void JoinableTest_0()
	{
		//Do nothing
	}

	void JoinableTest_1()
	{
		while (true)
		{
			//Do nothing.
		}
	}

	void WaitThread()
	{
		std::this_thread::sleep_for(10s);
	}

	void YieldWaitThread()
	{
		std::this_thread::yield();
		std::this_thread::sleep_for(10s);
	}

	void Thread()
	{
		//1. Simple Thread
		std::thread simpleThreadFunction(SimpleThread);
		simpleThreadFunction.join();

		//2. Single Variable thread
		std::thread singleVariableThreadFunction(SingleVariable, 5);
		singleVariableThreadFunction.join();

		//3. Simple thread that will join when completed. Joinable checks to see if the thread was started.
		std::thread joinableTest0ThreadFunction(JoinableTest_0);
		if (joinableTest0ThreadFunction.joinable())
		{
			joinableTest0ThreadFunction.join();
			std::cout << "Can join function JoinableTest_0\n";
		}
		else
		{
			std::cout << "Canont join function JoinableTest_0\n";
		}

		//4. Simple thread which yields its priority and then waits for 10 seconds before it can return. It will wait at the join.
		std::thread waitingThreadFunction(YieldWaitThread);
		waitingThreadFunction.join();

		//5. Simple thread which waits for 10 seconds before it can return. It will wait at the join.
		std::thread yieldWaitingThreadFunction(WaitThread);
		waitingThreadFunction.join();

		//6. Simple thread that will join when completed. On join the function will spin forever as the function is stuck in the while loop.
		std::thread joinableTest1ThreadFunction(JoinableTest_1);
		if (joinableTest1ThreadFunction.joinable())
		{
			joinableTest1ThreadFunction.join();
			std::cout << "Can join function JoinableTest_1\n";
		}
		else
		{
			std::cout << "Canont join function JoinableTest_1\n";
		}
	}
}



//#endif