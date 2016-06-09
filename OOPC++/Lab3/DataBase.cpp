#include  "DataBase.h"

DataBase::DataBase()
{
	
	m_count = 0;
	m_capasity = 0;
	m_pair = nullptr;
}

DataBase::~DataBase()
{

}

DataBase::DataBase(const DataBase& db)
{
	if(db.m_count!= 0)
	{
		m_count = db.m_count;
		m_capasity = db.m_count;
		m_pair = new Pair[m_count];
		m_pair = db.m_pair;
	}
	else
	{
		m_count = 0;
		m_capasity = 0;
		m_pair = nullptr;
	}
	//Не правильное распределение памяти
	
	//memcpy(m_pair, db.m_pair, m_count * sizeof(Pair));
}

DataBase::DataBase(DataBase && db)
{
	m_capasity = db.m_capasity;
	m_count = db.m_count;
	m_pair = std::move(db.m_pair);
	db.m_pair = nullptr;
}

void DataBase::RemoveEmployee(const char * emp)
{
	int cnt = 0;
	for (size_t i = 0; i < m_count; i++)
	{
		if (m_pair[i] == emp)
		{
			if(m_count == cnt)
			{
				m_count--;
			}
			else
			{
				m_pair[i] = std::move(m_pair[m_count - 1]);
				m_count--;
			}
		}
		cnt++;
	}
}

DataBase & DataBase::operator=(const DataBase & db)
{
	if (this != &db)
	{
		if(m_capasity < db.m_count)
		{
			m_count = db.m_count;
			m_capasity = m_count;
			m_pair = new Pair[m_count];
			for (size_t i = 0; i < m_count; i++)
			{
				m_pair[i] = db.m_pair[i];
			}
		}
		else
		{
			m_count = db.m_count;
			for (size_t i = 0; i < m_count; i++)
			{
				m_pair[i] = db.m_pair[i];
			}
		}
	}
	return *this;
}

DataBase & DataBase::operator=(DataBase && db)
{
	if (this != &db)
	{
		m_capasity = db.m_capasity;
		m_count = db.m_count;
		delete [] m_pair;
		m_pair = db.m_pair;
		db.m_pair = nullptr;
		/*
		for (size_t i = 0; i < m_count; i++)
		{
			m_pair[i] = std::move(db.m_pair[i]);
			db.m_pair[i] = nullptr;
		}
		*/
	}
	return *this;
}

Employee & DataBase::operator[](const char * key)
{
	for (size_t i = 0; i < m_count; i++)
	{
		if(m_pair[i] == key)
		{
			return m_pair[i].m_data;
		}
	}

	if (m_count == m_capasity)
	{
		m_capasity += Delta;
		Pair* tmp = new Pair[m_capasity];
		for (size_t i = 0; i < m_count; i ++)
		{
			tmp[i] = std::move(m_pair[i]);
		}
		delete[] m_pair;
		m_pair = tmp;
	}
	m_pair[m_count].m_key = key;
	m_count++;
	return m_pair[m_count -1].m_data;
}

std::ostream & operator<<(std::ostream & os, const DataBase & string)
{
	for (size_t i =0; i < string.m_count; i++)
	{	
		os << string.m_pair[i]<< std::endl;
	}
	return os;

}
