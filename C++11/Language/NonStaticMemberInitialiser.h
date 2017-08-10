#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
namespace NonStaticMemberInitialisation_Example
{
	void NonStaticMemberInitialisation()
	{
		// Default initialization prior to C++11
		class HumanCPP98
		{
			HumanCPP98() : age(0) {}
		private:
			unsigned age;
		};

		// Default initialization on C++11
		class HumanCPP11
		{
		private:
			unsigned age{ 0 };
		};
	}
}


//#endif