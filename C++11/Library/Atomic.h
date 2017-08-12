#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#define _ENABLE_ATOMIC_ALIGNMENT_FIX 1

#include <atomic>
#include <thread>


namespace Atomic_Example
{
	void SimpleFunction(std::_Atomic_int* _thisAtomic)
	{
		_thisAtomic->fetch_add(1, std::memory_order_relaxed);

		// Memory access rules for the fetch_* functions can be:
		//     - memory_order_relaxed		
		//     - memory_order_consume	
		//     - memory_order_acquire	
		//     - memory_order_release	
		//     - memory_order_acq_rel	
		//     - memory_order_seq_cst	
	}

	void Atomic()
	{
		//1. Simple type atomic
		std::atomic<int> atomicInt;

		//2. User define type atomic
		struct simpleType
		{
			int _a;
			int _b;
			int _c;
			int _d;
		};
		std::atomic<simpleType> atomicSimpleType;

		//3. Typedeffed int type in a thread.
		std::_Atomic_int simpleAtomic;
		simpleAtomic.store(0);

		std::thread threadOne	(SimpleFunction, &simpleAtomic);
		std::thread threadTwo	(SimpleFunction, &simpleAtomic);
		std::thread threadThree	(SimpleFunction, &simpleAtomic);
		std::thread threadFour	(SimpleFunction, &simpleAtomic);

		threadOne.join();
		threadTwo.join();
		threadThree.join();
		threadFour.join();

		std::cout << "Total value:" << simpleAtomic << '\n';

		//4. 
		struct largeArrayObject 
		{ 
			int a[512]; 
		};
		struct smallType
		{
			int _a;
			int _b;
		};
		std::atomic<largeArrayObject>	largeArrayTypeAtomic;
		std::atomic<simpleType>			simpleTypeAtomic;
		std::atomic<int>				intAtomic;
		std::atomic<smallType>			smallTypeAtomic;

		std::cout << "Result of std::atomic<LargeArrayObject> in std::atomic_is_lock_free: "<< std::atomic_is_lock_free(&largeArrayTypeAtomic) << '\n'
				  << "Result of std::atomic<simpleType> in std::atomic_is_lock_free: "		<< std::atomic_is_lock_free(&largeArrayTypeAtomic) << '\n'
				  << "Result of std::atomic<intAtomic> in std::atomic_is_lock_free: "		<< std::atomic_is_lock_free(&intAtomic) << '\n'
				  << "Result of std::atomic<smallTypeAtomic> in std::atomic_is_lock_free: "	<< std::atomic_is_lock_free(&smallTypeAtomic) << '\n';
	}
}



//#endif