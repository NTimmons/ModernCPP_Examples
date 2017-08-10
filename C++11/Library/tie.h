#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

void Tie()
{
	// With tuples...
	std::string playerName;
	std::tie(std::ignore, playerName, std::ignore) = std::make_tuple(91, "John Tavares", "NYI");

	// With pairs...
	std::string yes, no;
	std::tie(yes, no) = std::make_pair("yes", "no");
}

//#endif