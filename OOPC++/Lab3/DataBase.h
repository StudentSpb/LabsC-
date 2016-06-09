#pragma once
#include "Pair.h"

class DataBase
{
private:
	Pair* m_pair;
	size_t m_count; //���-�� ��������� � ����
	size_t m_capasity; //������� ����

	static const size_t Delta = 3;
public:
	//����������� � ����������
	DataBase();
	~DataBase();

	//������������ �����������
	DataBase(const DataBase& db);
	DataBase(DataBase&& db);

	void RemoveEmployee(const char *);

	DataBase& operator=(const DataBase& db);
	DataBase& operator=(DataBase&& db);

	Employee& operator[](const char* key);

	friend std::ostream& operator<<(std::ostream& os, const DataBase& string);
};

std::ostream& operator<<(std::ostream& os, const DataBase& string);