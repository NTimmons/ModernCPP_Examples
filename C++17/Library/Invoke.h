#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace Invoke_Example
{

	template <typename Callable>
	class Proxy
	{
		Callable c;
	public:
		Proxy(Callable c) : c(c) {}
		template <class... Args>
		decltype(auto) operator()(Args&&... args)
		{
			// ...
			return std::invoke(c, std::forward<Args>(args)...);
		}
	};

	auto add = [](int x, int y)
	{
		return x + y;
	};

	void Invoke()
	{
		//is_invocable replaces is_callable
		static_assert(std::is_invocable<decltype(add), int,int>::value);
		bool canWeCallInvokeWithTheseTypes = std::is_invocable<decltype(add), int, int>::value;

		//Getting the resulting type of an invoked function
		//Invoke result replaced result_of::type.
		std::invoke_result<decltype(add)> ResultTypedVariable;

		//Invoke class example
		Proxy<decltype(add)> p{ add };
		p(1, 2); // == 3
	}

}

//#endif