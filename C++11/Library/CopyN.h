#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <string>
#include <algorithm>
#include <iostream>

namespace CopyN_Example
{
	void CopyN()
	{
		std::string inString = "HelloThisIsAnLittleString";
		std::string outString;

		std::copy_n(inString.begin(), 5, std::back_inserter(outString));

		//Outputs "Hello"
		std::cout << outString << '\n'; 
	}
}

//#endif