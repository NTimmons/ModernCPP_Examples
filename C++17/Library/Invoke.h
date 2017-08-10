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

		Proxy<decltype(add)> p{ add };
		p(1, 2); // == 3
	}

}

//#endif