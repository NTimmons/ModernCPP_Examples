#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <array>

namespace Array_Example
{
	void Array()
	{
		//1. Simple initialisation
		std::array<int, 3> a = { 2, 1, 3 };
		std::sort(a.begin(), a.end()); // a == { 1, 2, 3 }
		for (int& x : a)
		{
			x *= 2; // a == { 2, 4, 6 }
		}

		//2. Array size and type getting.
		int tupleSize		 = std::tuple_size		< std::array<int, 3> >::value;  //tupleSize is 3
		
		struct MemberIsTypeOfArrayElement
		{
			//Gives the type of the element as a typedef.
			std::tuple_element	< 0, std::array<int, 3> >::type m_memberVariable;
		};

	}
}



//#endif