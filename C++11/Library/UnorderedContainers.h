#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <unordered_set>
#include <unordered_map>

void UnorderedContainers()
{
	std::unordered_set<int> unorderedSet;
	std::unordered_multiset<int> unorderedMultiset;
	std::unordered_map<int, int> unorderedMap;
	std::unordered_multimap<int, int> unorderedMultimap;
}

//#endif