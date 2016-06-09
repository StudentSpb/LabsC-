#pragma once
#include "myString.h"

class Employee
{
public:
	enum Sex {Undef, Male, Female};
private:
	MyString m_name;
	MyString m_fathername;
	MyString m_job;
	Sex m_sex;
	unsigned int m_salary;
	unsigned short m_age;

public:
	Employee(const char* name = "???", const char* fathername = "???", const char* job = "???", Sex sex = Undef, unsigned short age = 0, unsigned int salary  = 0);
	~Employee();

	Employee(const Employee& emp);
	Employee(Employee&& emp);

	Employee& operator=(const Employee& emp);
	Employee& operator=(Employee&& emp);

	friend std::ostream & operator<<(std::ostream & os, const Employee & string);
};
std::ostream & operator<<(std::ostream & os, const Employee & string);

