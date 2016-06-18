#pragma once
#include <iostream>

class MyString
{
private:
    char* m_pStr;	
public:
	const char* GetString() const;
	void SetString(char*);

	MyString();
	explicit MyString(const char* string);
	MyString(const MyString&);
	MyString(MyString &&);
	~MyString();

	void Swap(MyString& other_string);

	//Перегрузка операторов
	MyString& operator=(const MyString& other);
	MyString& operator=(const char* other);
	MyString& operator=(MyString &&);

	friend std::ostream& operator<<(std::ostream& os, const MyString& string);

	MyString& operator+=(const MyString& other);
	MyString operator+(const MyString& other);
};

std::ostream& operator<<(std::ostream& os, const MyString& string);
