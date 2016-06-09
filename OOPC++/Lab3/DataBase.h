#pragma once
#include "Pair.h"

class DataBase
{
private:
	Pair* m_pair;
	size_t m_count; //Кол-во элементов в базе
	size_t m_capasity; //Емкость базы

	static const size_t Delta = 3;
public:
	//Конструктор и деструктор
	DataBase();
	~DataBase();

	//Конструкторы копирования
	DataBase(const DataBase& db);
	DataBase(DataBase&& db);

	void RemoveEmployee(const char *);

	DataBase& operator=(const DataBase& db);
	DataBase& operator=(DataBase&& db);

	Employee& operator[](const char* key);

	friend std::ostream& operator<<(std::ostream& os, const DataBase& string);
};

std::ostream& operator<<(std::ostream& os, const DataBase& string);