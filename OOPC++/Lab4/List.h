#pragma once
#include "Circle.h"
#include "Node.h"
#include <ostream>

class List
{
	Node Head, Tail;
	unsigned int m_size;

public:
	List();
	List(const List& other);
	List(List&& other);

	~List();

	List& operator=(const List& other);
	List& operator=(List&& other);

	void AddToHead(const Circle& other);
	void AddToTail(const Circle& other);
	bool RemoveCircle(const Circle& other);
	int RevomeAllFound(const Circle& cir);
	void ClearList();
	void Sort();

	friend std::ostream & operator<<(std::ostream & os, const List & string);
	friend std::ifstream& operator >> (std::ifstream& ifs, List& l);
	friend std::ofstream& operator<<(std::ofstream& ofs, const List& list);
};
std::ostream & operator<<(std::ostream & os, const List & string);
std::ifstream& operator >> (std::ifstream& ifs, List& l);
std::ofstream& operator<<(std::ofstream& ofs, const List& list);