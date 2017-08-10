#pragma once

#ifdef NOT_SUPPORTED_ENABLED

namespace NontypeTemplateParametersWithAuto_Example
{
	template <auto ... seq>
	struct my_integer_sequence 
	{
		// Implementation here ...
	};

	void NontypeTemplateParametersWithAuto()
	{


		// Explicitly pass type `int` as template argument.
		auto seq = std::integer_sequence<int, 0, 1, 2>();
		// Type is deduced to be `int`.
		auto seq2 = my_integer_sequence<0, 1, 2>();
	}
}

#endif