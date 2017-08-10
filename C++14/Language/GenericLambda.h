#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace GenericLambda_Example
{
	void GenericLambda()
	{
		auto identity = [](auto x) { return x; };
		int three = identity(3); // == 3
		std::string foo = identity("foo"); // == "foo"
	}
}

//#endif