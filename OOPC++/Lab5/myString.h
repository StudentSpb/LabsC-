#pragma once

#include <iostream>
#include "Counter.h"


class MyString
{
private:
		Counter * m_pMyCounter;

public:
	//MyString();
	MyString(const char* string = "&");
	MyString(const MyString&);
	MyString(MyString &&);
	~MyString();

	//Перегрузка операторов
	MyString& operator=(const MyString& other);
	MyString& operator=(MyString &&);

	friend std::ostream& operator<<(std::ostream& os, const MyString& string);

	static void Print();
	static void ToUp();
	static void ToLow();
	static void PrintToAlph();
};

std::ostream& operator<<(std::ostream& os, const MyString& string);
