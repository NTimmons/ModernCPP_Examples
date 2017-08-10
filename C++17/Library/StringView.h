#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <string_view>
#include <algorithm>

namespace StringView_Example
{
	void StringView()
	{
		// Regular strings.
		std::string_view cppstr{ "foo" };
		// Wide strings.
		std::wstring_view wcstr_v{ L"baz" };
		// Character arrays.
		char array[3] = { 'b', 'a', 'r' };
		std::string_view array_v(array, sizeof array);
		std::string str{ "   trim me" };
		std::string_view v{ str };
		v.remove_prefix(std::min(v.find_first_not_of(" "), v.size()));
		str; //  == "   trim me"
		v; // == "trim me"
	}
}

//#endif