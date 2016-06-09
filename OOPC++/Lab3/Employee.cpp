#include "Employee.h"

Employee::Employee(const char * name, const char * fathername, const char* job, Sex sex, unsigned short age, unsigned int salary) 
	:m_name(name), m_fathername(fathername), m_job(job)
{
	//m_name = name;
	//m_fathername = fathername;
	//m_job = job;
	m_sex = sex;
	m_age = age;
	m_salary = salary;
}

Employee::~Employee()
{
	
}

//------------------------------------
Employee::Employee(const Employee & emp)
{
	m_age = emp.m_age;
	m_salary = emp.m_salary;
	m_sex = emp.m_sex;
	m_name = emp.m_name;
	m_fathername = emp.m_fathername;
	m_job = emp.m_job;
}

Employee::Employee(Employee && emp)
{
	m_age = emp.m_age;
	m_salary = emp.m_salary;
	m_sex = emp.m_sex;
	m_name = std::move(emp.m_name);
	m_fathername = std::move(emp.m_fathername);
	m_job = std::move(emp.m_job);
}

//------------------------------------
Employee & Employee::operator=(const Employee & emp)
{
	if(this != &emp)
	{
		m_age = emp.m_age;
		m_salary = emp.m_salary;
		m_sex = emp.m_sex;
		m_name = emp.m_name;
		m_fathername = emp.m_fathername;
		m_job = emp.m_job;
	}
	return *this;
}

Employee & Employee::operator=(Employee && emp)
{
	if (this != &emp)
	{
		m_age = emp.m_age;
		m_salary = emp.m_salary;
		m_sex = emp.m_sex;
		m_name = std::move(emp.m_name);
		m_fathername = std::move(emp.m_fathername);
		m_job = std::move(emp.m_job);
	}
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Employee & string)
{
	os << string.m_name <<" "<< string.m_fathername << " "<< string.m_age << " "<< string.m_job;
	return os;
}
