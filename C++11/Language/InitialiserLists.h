#pragma once
//#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace InitialiserLists_Example
{
	int sum(const std::initializer_list<int>& list)
	{
		int total = 0;
		for (auto& e : list)
		{
			total += e;
		}

		return total;
	}

	void InitialiserLists()
	{
		auto list = { 1, 2, 3 };
		sum(list); // == 6
		sum({ 1, 2, 3 }); // == 6
		sum({}); // == 0

	}

}

//#endif