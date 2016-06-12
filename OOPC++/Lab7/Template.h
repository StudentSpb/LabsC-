#pragma once
#include <algorithm>

template <typename T> void Swap(T& valueOne, T& valueTwo)
{
	T n = std::move(valueOne);
	valueOne = std::move(valueTwo);
	valueTwo = std::move(n);
}
