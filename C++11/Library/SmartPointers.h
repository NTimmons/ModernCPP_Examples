#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace SmartPointerExample
{
	struct Foo
	{
		void bar() {};

		int some;
		int value;
	};

	void f(Foo _p)
	{

	}

	void SmartPointers_1()
	{
		std::unique_ptr<Foo> p1{ new Foo{} };  // `p1` owns `Foo`
		if (p1) p1->bar();

		{
			std::unique_ptr<Foo> p2{ std::move(p1) };  // Now `p2` owns `Foo`
			f(*p2);

			p1 = std::move(p2);  // Ownership returns to `p1` -- `p2` gets destroyed
		}

		if (p1) p1->bar();
		// `Foo` instance is destroyed when `p1` goes out of scope
	}

	template <typename T>
	void foo(std::shared_ptr<T> t)
	{
		// Do something with `t`...
	}

	template <typename T>
	void bar(std::shared_ptr<T> t)
	{
		// Do something with `t`...
	}

	template <typename T>
	void baz(std::shared_ptr<T> t)
	{
		// Do something with `t`...
	}

	template <typename T>
	void SmartPointers_2()
	{
		std::shared_ptr<T> p1{ new T{} };
		// Perhaps these take place in another threads?
		foo(p1);
		bar(p1);
		baz(p1);
	}

}

//#endif