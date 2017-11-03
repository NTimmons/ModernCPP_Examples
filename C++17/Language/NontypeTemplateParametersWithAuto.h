#pragma once

#include <type_traits>
#include <iostream>
namespace NontypeTemplateParametersWithAuto_Example
{
	
	template <int ... seq>
	struct my_integer_sequence 
	{
		// Implementation here ...
	};

	#ifdef NOT_SUPPORTED_ENABLED
	template <auto ... seq>
	struct my_auto_sequence
	{
		// Implementation here ...
	};
	#endif
	
	void NontypeTemplateParametersWithAuto()
	{
		//std::integer_sequence is a compile time sequence of integers.

		// Explicitly pass type `int` as template argument. 
		std::integer_sequence<int, 0, 1, 2> seq = std::integer_sequence<int, 0, 1, 2>();
		std::cout << seq.size();


		// Type is deduced to be `int`.
		my_integer_sequence<0, 1, 2> seq2 = my_integer_sequence<0, 1, 2>();
	}
}