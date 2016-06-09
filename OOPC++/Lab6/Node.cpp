#include  "List.h"
#include "Node.h"
#include <algorithm>

Node::Node(): m_Data(nullptr)
{
	pPrev = pNext = nullptr;
}

Node::Node(Node * p, const Shape& shape):m_Data(shape.Clone())
{
		pPrev = p;
		pNext = p->pNext;
		p->pNext = this;
		pNext->pPrev = this;
}

Node::~Node()
{
	if(pPrev)
	{
		pPrev->pNext = pNext;
	}
	if(pNext)
	{
		pNext->pPrev = pPrev;
	}
	delete m_Data;
}
