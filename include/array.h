#pragma once

#include <array>
#include <iostream>
#include <string>

// A stack allocated array

template<typename T, size_t S>
class Array
{
public:
	// overload the [] operator to allow for array-like access
	T& operator[](size_t index)
	{
		/*if (!(index < S))
		{
			__debugbreak();
			throw std::out_of_range("Index out of range!");
		}*/
		return data[index];
	}
	const T& operator[](size_t index) const
	{
		return data[index];
	}
	// can be evaluated at compile time
	constexpr size_t size() const
	{
		return S;
	}
	T* value()
	{
		return data;
	}
	const T* value() const
	{
		return data;
	}
private:
	T data[S];
};

int arrayMain();