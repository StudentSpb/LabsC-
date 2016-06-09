#pragma once
#include "Circle.h"

class Node
{
	//Fields
	Node* pPrev;
	Node* pNext;
	Circle m_Data;

	Node();
	Node(Node* p, const Circle& circle);

	~Node();
	friend class List;
	friend std::ostream & operator<<(std::ostream & os, const List & string);
	friend std::ofstream& operator<<(std::ofstream& ofs, const List& list);
};