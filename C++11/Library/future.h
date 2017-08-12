#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <thread>
#include <future>
#include <vector>
#include <numeric>


namespace Promise_Example
{
	//TODO
	//std::promise
		//std::promise::set_exception
		//std::promise::set_exception_at_thread_exit
		//std::promise::set_value_at_thread_exit
	//std::future
		//std::future::wait_for
		//std::future::wait_until
		//std::future::valid
	//std::shared_future
	//std::packaged_task

	//std::future_status
	//std::future_error
	//std::future_category
	//std::future_errc

	void SimplePromiseThread( std::promise<int> _promise )
	{
		std::cout << "Thread started \n";
		_promise.set_value(10);

		std::this_thread::sleep_for(5s);
		std::cout << "Thread completed \n";
	}

	void Promise()
	{
		//Using a promise and future to get the result on a different thread.
		std::promise<int>	simplePromise;
		std::future<int>	simpleFuture = simplePromise.get_future();
		std::thread			work_thread(SimplePromiseThread, std::move(simplePromise));

		simpleFuture.wait();
		std::cout << "result = " << simpleFuture.get() << '\n';
		work_thread.join();

		std::cout << "Promise example is complete\n";
	}
}



//#endif