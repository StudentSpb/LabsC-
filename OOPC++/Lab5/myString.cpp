#include "myString.h"
#include <iostream>
using namespace std;

// Определение конструктора.


MyString::MyString(const char* string)
{
	m_pMyCounter = Counter::CreateCounter(string);// new Counter(string);
}

MyString::MyString(const MyString& other)
{
	m_pMyCounter = other.m_pMyCounter;
	m_pMyCounter->AddString();
}

//Move Конструктор копирования
MyString::MyString(MyString&& other)
{
	m_pMyCounter = other.m_pMyCounter;
	//m_pMyCounter->AddString();
	other.m_pMyCounter = nullptr;
}


// Определение деструктора.

MyString::~MyString()
{
	if(m_pMyCounter != nullptr)
		m_pMyCounter->RemoveString();
}

MyString& MyString::operator=(const MyString& other)
{
	if(this != &other)
	{
		m_pMyCounter->RemoveString();
		m_pMyCounter = other.m_pMyCounter;
		m_pMyCounter->AddString();
	}
	return *this;
}

MyString& MyString::operator=(MyString&& other)
{
	if (this != &other)
	{
		m_pMyCounter->RemoveString();
		m_pMyCounter = other.m_pMyCounter;
	//	m_pMyCounter->AddString();
		other.m_pMyCounter = nullptr;
	}
	return *this;
}

void MyString::Print()
{
	Counter::Print();
}

void MyString::ToUp()
{
	Counter::ToUp();
}

void MyString::ToLow()
{
	Counter::ToLow();
}

void MyString::PrintToAlph()
{
	Counter::PrintToAlph();
}

ostream & operator<<(ostream & os, const MyString & string)
{
	//os << "MyString: " << string.m_pMyCounter->m_pStr;
	return os;
}



