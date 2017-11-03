#pragma once

//#ifdef NOT_SUPPORTED_ENABLED

namespace LambdaCaptureByValue_Example
{
	void LambdaCaptureByValue()
	{
		struct MyObj
		{
			int value{ 123 };
			auto getValueCopy()
			{
				return[*this]{ return value; };
			}
			auto getValueRef()
			{
				return [this] { return value; };
			}
		};

		MyObj mo;
		auto valueCopy = mo.getValueCopy();
		auto valueRef = mo.getValueRef();
		mo.value = 321;
		valueCopy(); // 123
		valueRef(); // 321
	}
}

//#endif