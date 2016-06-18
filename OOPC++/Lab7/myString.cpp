#include <string>
#include "myString.h"
#include <iostream>
using namespace std;

// ќпределение конструктора.

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

//Move  онструктор копировани€
MyString::MyString(MyString&& other)
{
	m_pStr = other.m_pStr;
	other.m_pStr = nullptr;
}


// ќпределение деструктора.

MyString::~MyString()
{
	delete[] m_pStr;
}

void MyString::Swap(MyString& other_string)
{
	char* str = m_pStr;
	m_pStr = other_string.m_pStr;
	other_string.m_pStr = str;
	str = nullptr;
}

const char* MyString::GetString() const //делаем const чтобы нельз€ было изменить указатель
{
	return m_pStr;
}

void MyString::SetString(char * str)
{
	//освободить пам€ть
	delete [] m_pStr;
	size_t n = strlen(str) + 1;
	m_pStr = new char[n];
	strcpy(m_pStr, str);
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




