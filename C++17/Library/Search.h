#pragma once

#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
namespace Search_Example
{
	void Search()
	{
		std::string body = "Hello, this is a string search example";
		std::string searchTerm = "example";

		//Search algorithm can be: 
		//	default_searcher
  		//	boyer_moore_searcher
		//	boyer_moore_horspool_searcher

		auto it = std::search(body.begin(), body.end(),
													std::default_searcher(searchTerm.begin(), searchTerm.end()));
		
		if (it != body.end())
			std::cout << "The search term: " << searchTerm << " found at index -> "	<< it - body.begin() << '\n';
		else
			std::cout << "The search term: " << searchTerm << " not in body text\n";
	}
}

#endif