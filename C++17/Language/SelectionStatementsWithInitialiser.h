#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <iostream>

namespace SelectionStatementsWithInitialiser_Example
{
	//http://en.cppreference.com

	enum cases
	{
		OK,
		Bad
	};

	struct Foo
	{
		Foo(cases arg): m_value(arg) {};

		cases status() { return m_value; }
		void zip() { }
		void nozip() { }
		cases m_value;
	};

	void SelectionStatementsWithInitialiser()
	{
		/*
		{
			std::lock_guard<std::mutex> lk(mx);
			if (v.empty()) v.push_back(val);
		}
		// vs.
		if (std::lock_guard<std::mutex> lk(mx); v.empty())
		{
			v.push_back(val);
		}
		*/

		cases args = OK;
		Foo gadget(args);
		switch (auto s = gadget.status()) 
		{
		case OK: gadget.zip(); break;
		case Bad: gadget.nozip();
		}
		// vs.
		switch (Foo gadget(args); auto s = gadget.status()) 
		{
		case OK: gadget.zip(); break;
		case Bad: gadget.nozip();
		}
	}

}

//#endif