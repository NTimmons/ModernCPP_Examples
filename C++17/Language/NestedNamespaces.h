#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace NestedNamespaces_Example
{

	//C++
	//namespace A 
	//{
	//	namespace B 
	//	{
	//		namespace C 
	//		{
	//			int i;
	//		}
	//	}
	//}

	//C++17
	namespace A::B::C
	{
		int i;
	}

	void NestedNamespaces()
	{

	}

}

//#endif