#pragma once
#include <ostream>

class Node
{
	//Fields
	Node* pPrev;
	Node* pNext;
	Shape* m_Data;
	Node();
	Node(Node* p, const Shape& shape);

	~Node();
	friend class List;
	friend std::ostream & operator<<(std::ostream & os, const List & string);
	friend std::ofstream& operator<<(std::ofstream& ofs, const List& list);
};
