#pragma once

#ifdef NOT_SUPPORTED_ENABLED

//Allows for default template type.

namespace TemplateArgumentDeduction_Example
{
	template <typename T = float>
	struct MyContainer
	{
		T val;
		MyContainer() : val() {}
		MyContainer(T val) : val(val) {}
		// ...
	};


	void TemplateArgumentDeduction()
	{

		MyContainer c1{ 1 }; // OK MyContainer<int>
		MyContainer c2; // OK MyContainer<float>
	}
}



#endif