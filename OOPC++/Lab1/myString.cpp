#include <string>
#include "myString.h"
using namespace std;

// ����������� ������������.
MyString::MyString(char* string)
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

//Move ����������� �����������
MyString::MyString(MyString&& other)
{
	m_pStr = other.m_pStr;
	other.m_pStr = nullptr;
}


// ����������� �����������.

MyString::~MyString()
{
	delete[] m_pStr;
}


const char* MyString::GetString() const //������ const ����� ������ ���� �������� ���������
{
	return m_pStr;
}

void MyString::SetString(char * str)
{
	//���������� ������
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
	
	//move �����������
	return my_string;
}

