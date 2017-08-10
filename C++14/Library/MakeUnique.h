#pragma once

#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace MakeUnique
{
	foo(std::unique_ptr<T>{ new T{} }, function_that_throws(), std::unique_ptr<T>{ new T{} });

	foo(std::make_unique<T>(), function_that_throws(), std::make_unique<T>());

	void MakeUnique()
	{

	}
}

#endif