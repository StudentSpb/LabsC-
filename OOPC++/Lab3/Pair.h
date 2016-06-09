#pragma once
#include  "myString.h"
#include "Employee.h"

class Pair
{
private:
	MyString m_key;
	Employee m_data;

public:
	Pair(const char * key = "", Employee& emp = Employee());
	~Pair();

	Pair(const Pair& pair);
	Pair(Pair && pair);

	Pair& operator = (const Pair&);
	Pair& operator = (Pair&& pair);

	bool operator == (const char* key) const;

	friend class DataBase;
	friend std::ostream & operator<<(std::ostream & os, const Pair & string);
	
};
std::ostream & operator<<(std::ostream & os, const Pair & string);