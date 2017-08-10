#pragma once

#ifdef MSVC_NOT_SUPPORTED_ENABLED

#include <map>
#include <set>
#include <string>

namespace MapSetSplicing_Example
{

void MapSetSplicing()
{
	//Move from one map to another.

	std::map<int, std::string> src{ { 1, "one" },{ 2, "two" },{ 3, "buckle my shoe" } };
	std::map<int, std::string> dst{ { 3, "three" } };
	dst.insert(src.extract(src.find(1))); // Cheap remove and insert of { 1, "one" } from `src` to `dst`.
	dst.insert(src.extract(2)); // Cheap remove and insert of { 2, "two" } from `src` to `dst`.
								// dst == { { 1, "one" }, { 2, "two" }, { 3, "three" } };

	//Insert
	std::set<int> src{ 1, 3, 5 };
	std::set<int> dst{ 2, 4, 5 };
	dst.merge(src);
	// src == { 5 }
	// dst == { 1, 2, 3, 4, 5 }

	//Change key
	std::map<int, std::string> m{ { 1, "one" },{ 2, "two" },{ 3, "three" } };
	auto e = m.extract(2);
	e.key() = 4;
	m.insert(std::move(e));
	// m == { { 1, "one" }, { 3, "three" }, { 4, "two" } }
}

}

#endif