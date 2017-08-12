#pragma once

//#ifdef MSVC_NOT_SUPPORTED_ENABLED
#include <algorithm>
#include <vector>
#include <iostream>

//For shuffle
#include <random>

//minmax
#include <cstdlib>

namespace Algorithm_Example
{
	bool IsEqualOne(int _input)
	{
		if (_input == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	//Search functions
	void Algorithm_Search()
	{
		//all_of
		std::vector<int> ones = { 1,1,1,1,1,1,1 };
		bool results = std::all_of(ones.begin(), ones.end(), IsEqualOne);
		if (results)
		{
			std::cout << "All values in vector equal one.\n";
		}

		//none_of
		std::vector<int> zeroes = { 0,0,0,0,0,0,0 };
		results = std::none_of(zeroes.begin(), zeroes.end(), IsEqualOne);
		if (results)
		{
			std::cout << "None of the values in vector equal one.\n";
		}

		//any_of
		std::vector<int> mixedValue = { 0,0,0,0,1,1,1,1 };
		results = std::any_of(mixedValue.begin(), mixedValue.end(), IsEqualOne);
		if (results)
		{
			std::cout << "At least one of the values in vector equal one.\n";
		}

		//find_if_not
		std::vector<int>::iterator foundValue = std::find_if_not(mixedValue.begin(), mixedValue.end(), IsEqualOne);
		if (foundValue != mixedValue.end())
		{
			std::cout << "Found the first value that is equal to one.\n";
		}
	}

	void Algorithm_Partitioning()
	{
		//Partitioning operations
		//partition_copy
		//partition_point
	}

	void Algorithm_SortingOperations()
	{
		//Sorting Operations
		//is_sorted
		//is_sorted_until
	}

	void Algorithm_HeapOperations()
	{
		// Heap Operations
		//is_heap
		//is_heap_until
	}


	//Modifying sequence operations
	void Algorithm_ModifyingSequenceOperations()
	{
		//copy_if
		std::vector<int> mixedValueInput  = { 0,0,0,0,1,1,1,1 };
		std::vector<int> mixedValueOutput = { 0,0,0,0,0,0,0,0 };
		std::vector<int>::iterator foundValue = std::copy_if(mixedValueInput.begin(), mixedValueInput.end(), mixedValueOutput.begin(), IsEqualOne);
		
		//Ouput
		for (auto i : mixedValueOutput)
		{
			std::cout << i;
		}
		std::cout << "\n";

		//copy_n
		std::string in = "1234567890";
		std::string out;

		std::copy_n(in.begin(), 4, std::back_inserter(out));
		for (auto i : out)
		{
			std::cout << i;
		}
		std::cout << "\n";

		//shuffle
		std::vector<int> series = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		std::random_device rd;
		std::mt19937 mt(rd());
		std::shuffle(series.begin(), series.end(), mt);
		for (auto i : series)
		{
			std::cout << i;
		}
		std::cout << "\n";
	}

	void Algorithm_MinMaxOperations()
	{
		//Minimum/maximum operations
		//minmax
		std::pair<int, int> upperAndLower0 = std::minmax({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
		std::cout << upperAndLower0.first << ', ' << upperAndLower0.second << '\n';

		//minmax_element
		std::vector<int> series = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		std::pair<std::vector<int>::iterator, std::vector<int>::iterator> upperAndLower1;
		upperAndLower1 = std::minmax_element(series.begin(), series.end());
		std::cout << "min element index: " << (upperAndLower1.first		- series.begin()) << '\n';
		std::cout << "max element index: " << (upperAndLower1.second	- series.begin()) << '\n';

		//is_permutation
		bool isPermutation = false;

		std::vector<int> array1{ 1,2,3,4,5 };
		std::vector<int> array2{ 3,4,5,1,2 };
		isPermutation = std::is_permutation(array1.begin(), array1.end(), array2.begin()) << '\n';

		std::vector<int> array3{ 1,1,1,2,1 };
		isPermutation = std::is_permutation(array1.begin(), array1.end(), array3.begin()) << '\n';
	}


}


//#endif