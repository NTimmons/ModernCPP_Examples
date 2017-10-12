#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <cstdint>

namespace CStdInt_Example
{
	void CStdInt()
	{
		PTRDIFF_MIN;	//minimum value of object of std::ptrdiff_t type
		PTRDIFF_MAX;	//maximum value of object of std::ptrdiff_t type
		SIZE_MAX;		//maximum value of object of std::size_t type
		SIG_ATOMIC_MIN;	//minimum value of object of std::sig_atomic_t type
		SIG_ATOMIC_MAX;	//maximum value of object of std::sig_atomic_t type
		WCHAR_MIN;		//minimum value of object of wchar_t type
		WCHAR_MAX;		//maximum value of object of wchar_t type
		WINT_MIN;		//minimum value of object of std::wint_t type
		WINT_MAX;		//maximum value of object of std::wint_t type
	}
}


//#endif