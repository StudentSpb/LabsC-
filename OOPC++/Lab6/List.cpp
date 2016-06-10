#include "List.h"
#include "Node.h"
#include "Shape.h"
#include <algorithm>
#include "Rect.h"
#include "Circle.h"

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
			pThis->m_Data = pOther->m_Data;
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
	if (this != &other) {
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
		if (const Rect* rec = dynamic_cast<const Rect* >(&other))
		{
			if (p->m_Data == rec)
			{
				delete p;
				m_size--;
				return true;
			}
		}
		else
		{
			const Circle* cic = dynamic_cast<const Circle* >(&other);
			if (p->m_Data == cic)
			{
				delete p;
				m_size--;
				return true;
			}
		}			
		p = p->pNext;
	}
	return false;
}

int List::RevomeAllFound(const Shape& cir)
{
	int count = 0;
	Node* p = Head.pNext;
	Node* tmp2;
	while (p != &Tail) 
	{
		if (p->m_Data == &cir) 
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

void List::SortSqre()
{
	Node* p = Head.pNext;
	int j = m_size;
	for (int i = 0; i < m_size; i++)
	{
		Node* np = p;
		for (int k = 0; k <j-3; k++)
		{
			if (np->m_Data->GetSquare() > np->pNext->m_Data->GetSquare()) 
			{
				//Нужно править сортировку
				Node* prev = np->pPrev;
				Node* next = np->pNext;
				np->pNext = next->pNext;
				np->pNext->pPrev = np;
				np->pPrev = next;
				prev->pNext = next;
				next->pPrev = prev;
				next->pNext = np;
			}
			np = np->pNext;
		}
		j--;
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
		if (const Circle* rec = dynamic_cast<const Circle* >(p->m_Data))
		{
			os << *rec;
		}
		p = p->pNext;
	}
	return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const List& list) 
{
	/*
	ofs << "" << list.m_size << std::endl;
	Node* p = list.Head.pNext;
	while (p != &list.Tail) 
	{
		ofs << p->m_Data << std::endl;
		p = p->pNext;
	}
	*/
	return ofs;
}

std::ifstream& operator >> (std::ifstream& ifs, List& string) 
{
	/*
	int count;
	ifs >> count;
	int x;
	int y;
	float diametr;
	for (int i = 0; i < count; i++) 
	{
		ifs >> x >> y >> diametr;
		Circle cir(x, y, diametr);
		string.AddToTail(cir);
	}
	*/
	return ifs;
}

