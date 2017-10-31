#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <vector>
#include <iostream>
#include <iterator>

namespace ReverseIterators_Example
{
	void ReverseIterators()
	{
		//Simple reverse iterator on a vector
		std::vector<int> a = { 5,6,7 };
		std::reverse_iterator<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<int> > > > ai = std::rbegin(a);
		std::cout << *ai << '\n';

		// More readable as:
		std::vector<int> b = { 5,6,7 };
		auto bi = std::rbegin(b);
		std::cout << *bi << '\n';

		// Const reverse iterator iterator
		std::vector<int> c = { 5,6,7 };
		std::reverse_iterator<std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<int> > > > ci = std::crbegin(c);
		std::cout << *ci << '\n';

		// More readable:
		std::vector<int> d = { 5,6,7 };
		auto di = std::crbegin(d);
		std::cout << *di << '\n';
	}
	

}


//#endif