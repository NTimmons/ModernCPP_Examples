#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace VariableTemplates_Example
{
	template<class T>
	constexpr T pi = T(3.1415926535897932385);
	template<class T>
	constexpr T e = T(2.7182818284590452353);

	void VariableTemplates()
	{

	}
}



//#endif