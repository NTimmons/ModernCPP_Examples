#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <vector>

namespace TemplateAliases_Example
{
	template <typename T>
	void TemplateAliases()
	{
		using Vec = std::vector<T>;
		Vec<int> v{}; // std::vector<int>

		using String = std::string;
		String s{ "foo" };
	}
}

//#endif