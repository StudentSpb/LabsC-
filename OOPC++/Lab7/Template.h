#pragma once
#include "myString.h"

template <typename T> void Swap(T& valueOne, T& valueTwo)
{
	T n = std::move(valueOne);
	valueOne = std::move(valueTwo);
	valueTwo = std::move(n);
}

template <>
inline void Swap<MyString>(MyString& valueOne, MyString& valueTwo)
{
	valueOne.Swap(valueTwo);
}

//переброс указателей в Mystring

