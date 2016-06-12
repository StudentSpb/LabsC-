#include <string>
#include "myString.h"
#include <iostream>
using namespace std;

// Определение конструктора.

MyString::MyString()
{
	m_pStr = new char[1];
	m_pStr[0] = 0;
}


MyString::MyString(const char* string)
{
	size_t n = strlen(string) + 1;
	m_pStr = new char [n];
	strcpy(m_pStr, string);
}

MyString::MyString(const MyString& other)
{
	size_t n = strlen(other.m_pStr) + 1;
	m_pStr = new char[n];
	strcpy(m_pStr, other.m_pStr);
}

//Move Конструктор копирования
MyString::MyString(MyString&& other)
{
	m_pStr = other.m_pStr;
	other.m_pStr = nullptr;
}


// Определение деструктора.

MyString::~MyString()
{
	delete[] m_pStr;
}


const char* MyString::GetString() const //делаем const чтобы нельзя было изменить указатель
{
	return m_pStr;
}

void MyString::SetString(char * str)
{
	//освободить память
	delete [] m_pStr;
	size_t n = strlen(str) + 1;
	m_pStr = new char[n];
	strcpy(m_pStr, str);
}

MyString GetMyString(const char* str, ...)
{

	size_t n = 0;
	for (const char **p = &str; *p != 0; *p++)
	{
		n = n + strlen(*p);
	}
	char* myStr = new char[n+1];

	myStr[0] = 0;
	for (const char **p = &str; *p != 0; *p++)
	{
		strcat(myStr, *p);
	}

	MyString my_string(myStr);
	delete[] myStr;
	
	//move констукртор
	return my_string;
}

std::ostream & operator<<(std::ostream & os, const MyString & string)
{
	os << "MyString: " << string.m_pStr;
	return os;
}

MyString& MyString::operator=(const MyString& other)
{
	if(this != &other)
	{
		delete[] m_pStr;
		size_t n = strlen(other.m_pStr) + 1;
		m_pStr = new char[n];
		strcpy(m_pStr, other.m_pStr);
	}
	return *this;
}

MyString& MyString::operator=(MyString&& other)
{
	if (this != &other)
	{
		delete[] m_pStr;
		m_pStr = other.m_pStr;
		other.m_pStr = nullptr;
	}
	return *this;
}

MyString& MyString::operator=(const char* other)
{
	delete[] m_pStr;
	size_t n = strlen(other ) + 1;
	m_pStr = new char[n];
	strcpy(m_pStr, other);
	return *this;
}



MyString&  MyString::operator+=(const MyString & other)
{
	char * str = new char[strlen(m_pStr) + strlen(other.m_pStr) +1];
	str[0] = 0;
	strcpy(str, m_pStr);
	strcat(str, other.m_pStr);
	//strcpy(m_pStr, str);
	delete[] m_pStr;
	m_pStr = str;
	return *this;
}

MyString MyString::operator+(const MyString & other)
{
	char * str = new char[strlen(m_pStr) + strlen(other.m_pStr) + 1];
	str[0] = 0;
	strcpy(str, m_pStr);
	strcat(str, other.m_pStr);
	MyString string(str);
	delete[] str;

	return string;
}




