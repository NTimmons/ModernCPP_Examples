#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <tuple>

void Tuples()
{
	// `playerProfile` has type `std::tuple<int, std::string, std::string>`.
	auto playerProfile = std::make_tuple(51, "Frans Nielsen", "NYI");
	std::get<0>(playerProfile); // 51
	std::get<1>(playerProfile); // "Frans Nielsen"
	std::get<2>(playerProfile); // "NYI"
}

//#endif