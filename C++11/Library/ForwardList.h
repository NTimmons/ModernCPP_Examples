#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <forward_list>

namespace ForwardList_Example
{

	void ForwardList()
	{
		std::forward_list<int> forwardList;

		forwardList.push_front(1);
		forwardList.push_front(2);
		forwardList.push_front(3);
		forwardList.push_front(4);
		forwardList.push_front(5);

		forwardList.clear();
	}
}

//#endif