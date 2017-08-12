#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace Move_Example
{
	void Move()
	{
		std::unique_ptr<int> p1{ new int };
		//ERROR-> std::unique_ptr<int> p2 = p1; // error -- cannot copy unique pointers
		std::unique_ptr<int> p3 = std::move(p1); // move `p1` into `p2`
												 // now unsafe to dereference object held by `p1`
	}
}


//#endif