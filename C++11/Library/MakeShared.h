#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace MakeShared_Example
{
	template <typename T>
	void Foo(std::shared_ptr<T> _ptrInOne, int _a, std::shared_ptr<T> _ptrInTwo)
	{}

	int function_that_throws()
	{
		return 0;
	}

	template <typename T>
	void MakeShared()
	{
		foo(std::shared_ptr<T>{ new T{} }, function_that_throws(), std::shared_ptr<T>{ new T{} });
		foo(std::make_shared<T>(), function_that_throws(), std::make_shared<T>());
	}
}





//#endif