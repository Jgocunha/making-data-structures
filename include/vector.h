#pragma once

#include <iostream>

// A heap allocated array

template<typename T>
class Vector
{
private:
	T* data; // pointer to the array
	size_t size; // number of elements in the array
	size_t capacity; // size of the array
public:
	Vector()
	{
		// default constructor
		data = nullptr;
		size = 0;
		capacity = 0;
		reAllocate(2);
	}

	~Vector()
	{
		clear();
		::operator delete(data, capacity * sizeof(T));
	}

	void pushBack(const T& value)
	{
		// if the size is equal to the capacity
		// increase the capacity by half
		if (size == capacity)
			reAllocate(capacity + capacity/2);

		data[size] = value;
		size++;
	}
	
	void pushBack(T&& value)
	{
		// if the size is equal to the capacity
		// increase the capacity by half
		if (size == capacity)
			reAllocate(capacity + capacity / 2);

		data[size] = std::move(value);
		size++;
	}

	template<typename... Args>
	T& emplaceBack(Args&&... args)
	{
		// if the size is equal to the capacity
		// increase the capacity by half
		if (size >= capacity)
			reAllocate(capacity + capacity / 2);
		//data[size] = T(std::forward<Args>(args)...);
		new(&data[size]) T(std::forward<Args>(args)...);
		return data[size++];
	}

	void popBack()
	{
		if (size > 0)
		{
			size--;
			data[size].~T();
		}
	}

	void clear()
	{
		for (size_t i = 0; i < size; i++)
			data[i].~T();
		size = 0;
	}

	const T& operator[](size_t index) const
	{
		// check if the index is out of range
		if (!(index < size))
		{
			__debugbreak();
			throw std::out_of_range("Index out of range!");
		}
		return data[index];
	}

	T& operator[](size_t index)
	{
		// check if the index is out of range
		if (!(index < size))
		{
			__debugbreak();
			throw std::out_of_range("Index out of range!");
		}
		return data[index];
	}


	size_t getSize() const
	{
		return size;
	}

private:
	void reAllocate(size_t newCapacity)
	{
		// 1. allocate a new array
		T* newArray = (T*)::operator new(newCapacity*sizeof(T));

		// 2. copy the data from the old array to the new array

		if (newCapacity < size)
			size = newCapacity;

		for (size_t i = 0; i < size; i++)
			new (&newArray[i]) T(std::move(data[i]));
		
		// 3. delete the old array
		for (size_t i = 0; i < size; i++)
			data[i].~T();
		::operator delete(data, capacity * sizeof(T));
		//delete[] data;
		// set the data pointer to the new array
		data = newArray;
		// set the capacity to the new capacity
		capacity = newCapacity;
	}
};


int vectorMain();

// print vector
template<typename T>
void printVector(const Vector<T>& vector)
{
	std::cout << "A vector with size " << vector.getSize() << std::endl;
	for (size_t i = 0; i < vector.getSize(); i++)
		std::cout << vector[i] << std::endl;
}