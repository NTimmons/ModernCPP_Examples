#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <typeindex>

//For output
#include <iostream>

namespace TypeIndex_Example
{
	void TypeIndex()
	{
		std::type_index intTypeIndex(typeid(int));

		//Outputs 'int'
		std::cout << intTypeIndex.name() << "\n";
	}
}


//#endif