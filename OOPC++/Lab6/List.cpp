#include "List.h"
#include "Node.h"
#include "Shape.h"
#include "Rect.h"
#include "Circle.h"
#include <iostream>
#include <fstream>

List::List()
{
	Head.pNext= &Tail;
	Tail.pPrev = &Head;
	m_size = 0;
}

List::List(const List & other)
{
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	m_size = 0;
	if (other.m_size != 0) {
		Node* tmp = other.Head.pNext;
		for (int i = 0; i < other.m_size; i++) 
		{
			this->AddToTail(*tmp->m_Data);
			tmp = tmp->pNext;
		}
	}
}

List::List(List && other)
{
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	m_size = 0;
	if (other.m_size != 0) 
	{
		Head.pNext = other.Head.pNext;
		Head.pNext->pPrev = &Head;
		other.Head.pNext = &Tail;
		Tail.pPrev = other.Tail.pPrev;
		Tail.pPrev->pNext = &Tail;
		other.Tail.pPrev = &Head;
		m_size = other.m_size;
		other.m_size = 0;
	}
}

List::~List()
{
	while(Head.pNext != &Tail)
	{
		delete Head.pNext;
	}
}

List & List::operator=(const List & other)
{
	if (this != &other) 
	{
		Node* pThis;
		Node* pOther;
		if (other.m_size == 0) //Если размер Other = 0
		{														
			this->ClearList();
			return *this;
		}
		/*
		else if (m_size == other.m_size) //Если размеры равны
		{												
			pThis = Head.pNext;
			pOther = other.Head.pNext;
			for (int i = 0; i < m_size; i++) 
			{
				pThis->m_Data = pOther->m_Data;
				pThis = pThis->pNext;
				pOther = pOther->pNext;
			}
		}
		else if (m_size > other.m_size) //Если размер this меньше other
		{												
			pThis = Head.pNext;
			pOther = other.Head.pNext;
			
			for (int i = 0; i < other.m_size; i++)
			{
				pThis->m_Data = pOther->m_Data;
				pThis = pThis->pNext;
				pOther = pOther->pNext;
			}
			Node* pThisEnd = Tail.pPrev;
			for (int i = 0; i < m_size; i++)
			{
				delete pThisEnd;
				pThisEnd = Tail.pPrev;
			}
			pThis->pNext = &Tail;
			Tail.pPrev = pThis;
			m_size = other.m_size;
		}
		else if (m_size < other.m_size) //Если размер this больше other
		{											
			pThis = Head.pNext;
			pOther = other.Head.pNext;
			
			for (int i = 0; i < m_size; i++)
			{
				pThis->m_Data = pOther->m_Data;
				pThis = pThis->pNext;
				pOther = pOther->pNext;
			}
			for (int i = 0; i < other.m_size; i++)
			{
				this->AddToTail(pOther->m_Data);
				pOther = pOther->pNext;
			}
		}
		*/

		int count = (this->m_size < other.m_size) ? this->m_size:other.m_size;
		pThis = Head.pNext;
		pOther = other.Head.pNext;
		for (int i = 0; i < count; i++)
		{
			try
			{
				*pThis->m_Data = *pOther->m_Data;
			}
			catch (const char*)
			{
				delete  pThis->m_Data;
				pThis->m_Data = pOther->m_Data->Clone();
			}

			pThis = pThis->pNext;
			pOther = pOther->pNext;
		}
		Node* pThisEnd = Tail.pPrev;
		for(int i = count; i< this->m_size; i ++)
		{
			delete pThisEnd;
			pThisEnd = Tail.pPrev;
		}
		for (int i = count; i < other.m_size; i++)
		{
			this->AddToTail(*pOther->m_Data);
			pOther = pOther->pNext;
		}
		m_size = other.m_size;
	}
	return *this;
}

List & List::operator=(List && other)
{
	if (this != &other) 
	{
		this->ClearList();
		if (other.m_size != 0) {
			Head.pNext = other.Head.pNext;
			Head.pNext->pPrev = &Head;
			other.Head.pNext = &Tail;
			Tail.pPrev = other.Tail.pPrev;
			Tail.pPrev->pNext = &Tail;
			other.Tail.pPrev = &Head;
			m_size = other.m_size;
			other.m_size = 0;
		}
	}
	return *this;
}

void List::AddToHead(const Shape& other)
{
	new Node(&Head, other);
	m_size++;
}

void List::AddToTail(const Shape & other)
{
	new Node(Tail.pPrev, other);
	m_size++;
}

bool List::Remove(const Shape & other)
{
	Node* p = Head.pNext;
	while (p != &Tail)
	{
		if (*p->m_Data == other)
		{
			delete p;
			m_size--;
			return true;
		}
		p = p->pNext;
	}
	return false;
}

int List::RevomeAllFound(const Shape& other)
{
	int count = 0;
	Node* p = Head.pNext;
	Node* tmp2;
	while (p != &Tail) 
	{
		if (*p->m_Data == other)
		{
			tmp2 = p->pPrev;
			delete p;
			m_size--;
			p = tmp2;
			count++;
		}
		p = p->pNext;
	}
	return count;
}

void List::ClearList()
{
	while (Head.pNext != &Tail)
	{
		delete Head.pNext;
	}
}

void List::SortSqre(Sort typeSort)
{
	Node* p = Head.pNext;
	for (int k = 0; k < m_size-1; k++)
	{
		Node* np = p;
		for (int i = 0; i < m_size - k - 1; i++)
		{
			switch (typeSort)
			{
			case mSquare:
				if (np->m_Data->GetSquare() > np->pNext->m_Data->GetSquare())
				{
					std::swap(np->m_Data, np->pNext->m_Data);
				}
				break;
			case mColor:
				if (np->m_Data->GetColor() > np->pNext->m_Data->GetColor())
				{
					std::swap(np->m_Data, np->pNext->m_Data);
				}
				break;
			}
			np = np->pNext;
		}
	}
}

std::ostream & operator<<(std::ostream & os, const List & string) 
{
	Node* p = string.Head.pNext;
	while(p != &string.Tail)
	{
		if (const Rect* rec = dynamic_cast<const Rect* >(p->m_Data))
		{
			os << *rec;
		}
		if (const Circle* cir = dynamic_cast<const Circle* >(p->m_Data))
		{
			os << *cir;
		}
		p = p->pNext;
	}
	return os;
}


std::ofstream& operator<<(std::ofstream& ofs, const List& list) 
{
	
	ofs << "" << list.m_size << std::endl;
	Node* p = list.Head.pNext;
	while (p != &list.Tail) 
	{
		if (const Rect* rec = dynamic_cast<const Rect* >(p->m_Data))
		{
			ofs << *rec;
		}
		if (const Circle* cir = dynamic_cast<const Circle* >(p->m_Data))
		{
			ofs << *cir;
		}
		//ofs << *p->m_Data << std::endl;
		p = p->pNext;
	}
	return ofs;
}


std::ifstream& operator >> (std::ifstream& ifs, List& string) 
{
	
	int count;
	ifs >> count;
	int obj;
	for (int i = 0; i < count; i++) 
	{
		ifs >> obj;
		if(obj == 1)
		{
			int x;
			int y;
			float diametr;
			ifs >> x >> y >> diametr;
			Circle cir(x, y, diametr);
			string.AddToTail(cir);
		}
		else
		{
			int bot;
			int top;
			int left;
			int right;
			ifs >> bot >> top >> left>> right;
			Rect rec(left, right, top, bot);
			string.AddToTail(rec);
		}
	}
	return ifs;
}

