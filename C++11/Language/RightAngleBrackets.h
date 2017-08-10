#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <map>

namespace RightAngleBracket_Example
{
	//Required spacing on CPP98
	typedef std::map<int, std::map <int, std::map <int, int> > > cpp98LongTypedef;

	//Correct parsing on CPP11
	typedef std::map<int, std::map <int, std::map <int, int>>>   cpp11LongTypedef;

	void RightAngleBrackets()
	{

	}
}



//#endif