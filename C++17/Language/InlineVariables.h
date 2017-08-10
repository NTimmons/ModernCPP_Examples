#pragma once

#ifdef NOT_SUPPORTED_ENABLED

namespace InlineVariables_Example
{
	void InlineVariables()
	{
		// Disassembly example using compiler explorer.
		struct S { int x; };
		inline S x1 = S{ 321 }; // mov esi, dword ptr [x1]
								// x1: .long 321

		S x2 = S{ 123 };        // mov eax, dword ptr [.L_ZZ4mainE2x2]
								// mov dword ptr [rbp - 8], eax
								// .L_ZZ4mainE2x2: .long 123
	}
}

#endif