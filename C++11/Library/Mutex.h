#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <thread>
#include <mutex>
#include <iostream>
#include <condition_variable>

namespace Mutex_Example
{
	//Shared objects
	int			g_simpleValue = 0;
	std::mutex	g_mutexForSimpleValue; 

	//Unique lock objects
	std::mutex		g_mutexForUniqueLockValue0;
	std::mutex		g_mutexForUniqueLockValue1;
	int				g_uniqueLockValue0 = 0;
	int				g_uniqueLockValue1 = 0;
	std::once_flag	g_callOnceFlag;

	//Try lock mutexs
	std::mutex	g_mutexForUniqueTryLockValue0;
	int			g_uniqueTryLockValue0 = 0;

	//Conditional Variable Example
	std::mutex					g_conditionalVariableMutex;
	std::condition_variable		g_conditionalVariable;
	std::condition_variable_any g_conditionalVariable_Any;
	bool						g_workerFinished = false;

	//Forward decl.
	void SimpleUniqueLockThread();
	void SimpleTryLockThread();
	void SimpleMutexOnlyThread();
	void SimpleScopedLockGuardThread();
	void SimpleOneCallFunction();
	void DoOnceThread();
	void AdoptLockThread();
	void TryToLockThread();
	void SimpleConditionalVariableThread_Main();
	void SimpleConditionalVariableThread_Notifier();
	void ConditionalVariableEndThread_Main();
	void ConditionalVariableEndThread_Notifier();
	void ConditionalVariableAnyThread_Main();
	void ConditionalVariableAnyThread_Notifier();

	void Mutex()
	{
		//1. Simple lockguard example
		std::thread t0(SimpleScopedLockGuardThread);
		std::thread t1(SimpleScopedLockGuardThread);
		t0.join();
		t1.join();
		std::cout << "Finished Lockguard example\n";

		//2. Simple Mutex only example
		std::thread t2(SimpleMutexOnlyThread);
		std::thread t3(SimpleMutexOnlyThread);
		t2.join();
		t3.join();
		std::cout << "Finished Mutex only example\n";

		//3. Simple trylock example
		std::thread t4(SimpleTryLockThread);
		std::thread t5(SimpleTryLockThread);
		t4.join();
		t5.join();
		std::cout << "Finished trylock example\n";

		//4. Deferred lock example
		// Creates a lock without locking it by using std::deferred and then locks and unlocks it.
		std::unique_lock<std::mutex> uniqueLock0(g_mutexForSimpleValue, std::defer_lock);
		uniqueLock0.lock();
		if(uniqueLock0.owns_lock())
			uniqueLock0.unlock();

		//5. Simple Multiple UniqueLock Example
		std::thread t6(SimpleUniqueLockThread);
		std::thread t7(SimpleUniqueLockThread);
		t6.join();
		t7.join();
		std::cout << "Finished UniqueLock example\n";

		//6. Call Once Example
		std::thread onceThread0(DoOnceThread);
		std::thread onceThread1(DoOnceThread);
		std::thread onceThread2(DoOnceThread);
		std::thread onceThread3(DoOnceThread);
		onceThread0.join();
		onceThread1.join();
		onceThread2.join();
		onceThread3.join();
		std::cout << "Finished call once example\n";

		//7. Adopt Lock Example
		std::thread t8(AdoptLockThread);
		std::thread t9(AdoptLockThread);
		t8.join();
		t9.join();
		std::cout << "Finished Adopt Lock example\n";

		//8. TryTolock Example
		std::thread t10(TryToLockThread);
		std::thread t11(TryToLockThread);
		t10.join();
		t11.join();
		std::cout << "Finished TryTolock example\n";

		//9. Conditional Variable
		std::thread t12(SimpleConditionalVariableThread_Main);
		std::thread t13(SimpleConditionalVariableThread_Notifier);
		t12.join();
		t13.join();
		std::cout << "Finished Conditional Variable example\n";

		//10. Conditional Variable change at end of thread.
		std::thread t14(ConditionalVariableEndThread_Main);
		std::thread t15(ConditionalVariableEndThread_Notifier);
		t14.join();
		t15.join();
		std::cout << "Finished Conditional Variable Notify at end example\n";

		//11. std::condition_variable_any is the same as a condition variable but can work with locks other than
		//	  unique_lock
		std::thread t16(ConditionalVariableAnyThread_Main);
		std::thread t17(ConditionalVariableAnyThread_Notifier);
		t14.join();
		t15.join();
		std::cout << "Finished Conditional Variable Any at end example\n";
	}

	//Thread functions for the examples
	void SimpleScopedLockGuardThread()
	{
		std::lock_guard<std::mutex> lock(g_mutexForSimpleValue);
		std::this_thread::sleep_for(5s);
		++g_simpleValue;

		std::cout << "Incremented g_simpleValue\n";
	}

	void SimpleMutexOnlyThread()
	{
		g_mutexForSimpleValue.lock();
		std::this_thread::sleep_for(5s);
		++g_simpleValue;
		g_mutexForSimpleValue.unlock();

		std::cout << "Incremented g_simpleValue\n";
	}

	void SimpleTryLockThread()
	{
		if (g_mutexForSimpleValue.try_lock())
		{
			std::this_thread::sleep_for(5s);
			++g_simpleValue;
			g_mutexForSimpleValue.unlock();

			std::cout << "Incremented g_simpleValue\n";
		}
		else
		{
			std::cout << "Couldnt acquire lock for g_simpleValue\n";
		}
	}

	void SimpleUniqueLockThread()
	{
		// Create the lock but doesnt lock it.
		std::unique_lock<std::mutex> uniqueLock0(g_mutexForUniqueLockValue0, std::defer_lock);
		std::unique_lock<std::mutex> uniqueLock1(g_mutexForUniqueLockValue1, std::defer_lock);

		// Simultaneous lock of both locks. This prevents stalling when one locks but not the other on this thread
		// and the other locks on a different thread.
		std::lock(uniqueLock0, uniqueLock1);

		g_uniqueLockValue0++;
		g_uniqueLockValue1++;

		std::cout << "Incremented g_simpleValue\n";
	}

	void SimpleOneCallFunction()
	{
		std::cout << "This will only be printed once \n";
	}

	void DoOnceThread()
	{
		std::call_once(g_callOnceFlag, SimpleOneCallFunction);
	}

	void AdoptLockThread()
	{
		g_mutexForSimpleValue.lock();
		// Takes the locked mutex and then wraps it so it will be unlocked when it comes off the stack.
		std::lock_guard<std::mutex> lock1(g_mutexForSimpleValue, std::adopt_lock);
		std::this_thread::sleep_for(5s);
		++g_simpleValue;
	}

	void TryToLockThread()
	{
		// Create the lock and calls the try_lock function on the mutex
		std::unique_lock<std::mutex> uniqueLock0(g_mutexForUniqueTryLockValue0, std::try_to_lock);
		if (uniqueLock0.owns_lock())
		{
				// The first thread will access here.
				g_uniqueTryLockValue0++;
				std::cout << "Incremented g_simpleValue\n";
				return;
		}

		//The second thread will hit here as it fails to lock the mutex and continues instead of waiting.
		std::cout << "Failed to get lock to change g_simpleValue\n";
	}

	void SimpleConditionalVariableThread_Main()
	{
		std::unique_lock<std::mutex> lock(g_conditionalVariableMutex);
		g_conditionalVariable.wait(lock);
		std::cout << "Ending main CV thread as work is done.\n";
	}

	void SimpleConditionalVariableThread_Notifier()
	{
		g_workerFinished = false;
		std::cout << "Starting work for CV threads.\n";
		std::this_thread::sleep_for(10s);

		std::lock_guard<std::mutex> lock(g_conditionalVariableMutex);
		g_workerFinished = true;
		g_conditionalVariable.notify_all();
	}

	void ConditionalVariableEndThread_Main()
	{
		std::unique_lock<std::mutex> lock(g_conditionalVariableMutex);
		g_conditionalVariable.wait(lock);
		std::cout << "Ending main CV thread as work is done.\n";
	}

	void ConditionalVariableEndThread_Notifier()
	{
		g_workerFinished = false;

		std::unique_lock<std::mutex> lock(g_conditionalVariableMutex);
		std::notify_all_at_thread_exit(g_conditionalVariable, std::move(lock));

		std::cout << "Starting work for CV threads.\n";
		std::this_thread::sleep_for(10s);

		g_workerFinished = true;
	}

	void ConditionalVariableAnyThread_Main()
	{
		g_conditionalVariableMutex.lock();
		g_conditionalVariable_Any.wait(g_conditionalVariableMutex);
		g_conditionalVariableMutex.unlock();
		
		std::cout << "Ending main CV thread as work is done.\n";
	}

	void ConditionalVariableAnyThread_Notifier()
	{
		g_workerFinished = false;
		std::cout << "Starting work for CV threads.\n";
		std::this_thread::sleep_for(10s);

		std::lock_guard<std::mutex> lock(g_conditionalVariableMutex);
		g_workerFinished = true;
		g_conditionalVariable.notify_all();
	}
}



//#endif