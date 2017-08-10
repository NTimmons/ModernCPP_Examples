#pragma once

#ifdef MSVC_NOT_SUPPORTED_ENABLED

namespace InitialisationOfEnums_Example
{
	void InitialisationOfEnums()
	{
		enum byte : unsigned char {};
		byte b{ 0 }; // OK
		byte c{ -1 }; // ERROR
		byte d = byte{ 1 }; // OK
		byte e = byte{ 256 }; // ERROR
	}
}

#endif