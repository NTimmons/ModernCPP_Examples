#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace InlineNamespaces_Example
{
	namespace Program 
	{
		namespace Version1 
		{
			int getVersion() { return 1; }
			bool isFirstVersion() { return true; }
		}
		inline namespace Version2 
		{
			int getVersion() { return 2; }
		}
	}

	int version{ Program::getVersion() };              // Uses getVersion() from Version2
	int oldVersion{ Program::Version1::getVersion() }; // Uses getVersion() from Version1
	//Error -> bool firstVersion{ Program::isFirstVersion() };    // Does not compile when Version2 is added



	void InlineNamespaces()
	{

	}
}


//#endif