#include "Pair.h"



Pair::Pair(const char * key, Employee& emp)
{
	m_key = key;
	m_data = emp;
}

Pair::~Pair()
{
}


Pair::Pair(const Pair & pair)
{
	m_key = pair.m_key;
	m_data = pair.m_data;
}

Pair::Pair(Pair && pair)
{
	m_key = std::move(pair.m_key);
	m_data = std::move(pair.m_data);
}


Pair & Pair::operator=(const Pair & pair)
{
	if (this != &pair)
	{
		m_key = pair.m_key;
		m_data = pair.m_data;
	}
	return* this;
}

Pair & Pair::operator=(Pair && pair)
{
	m_key = std::move(pair.m_key);
	m_data = std::move(pair.m_data);
	return* this;
}


bool Pair::operator==(const char * key) const
{
	if (strcmp(m_key.GetString(), key) == 0)
	{
		return true;
	}
	return false;
}

std::ostream & operator<<(std::ostream & os, const Pair & string)
{
	os << string.m_key << ": "<< string.m_data;
	return os;
}
