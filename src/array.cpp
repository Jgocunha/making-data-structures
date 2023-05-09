
#include "array.h"

int arrayMain()
{
	// stack allocated array. size must be known at compile time
	int array[5]; 

	// heap allocated array. size can be known at runtime
	int* heapArray = new int[5];
	// free the memory allocated on the heap
	delete[] heapArray; 

	// stack allocated array with size 10. std lib template class
	std::array<int, 10> collection; 

	// using my array class
	constexpr int size = 5;
	Array<int, size> data;

	// allows for asserts at compile time
	static_assert(data.size() < 10, "Size is too large!");

	// fill the array with values
	for (size_t i = 0; i < data.size(); i++)
	{
		data[i] = i;
	}

	// print the values in the array
	std::cout << "An integer array with size " << data.size() << std::endl;
	for (size_t i = 0; i < data.size(); i++)
	{
		std::cout << data[i] << std::endl;
	}

	// create another array with the same size as data
	Array<std::string, data.size()> newArray;

	newArray[0] = "Hello";
	newArray[1] = "World";

	std::cout << "A string array with size " << newArray.size() << std::endl;
	for (size_t i = 0; i < data.size(); i++)
	{
		std::cout << newArray[i] << std::endl;
	}


	return 0;
}