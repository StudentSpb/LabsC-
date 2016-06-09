#include  "List.h"
#include "Node.h"
#include <algorithm>

Node::Node()
{
	pPrev = pNext = nullptr;
}

Node::Node(Node * p, const Circle& circle):m_Data(circle)
{
	//if(p->pPrev == nullptr)
	//{
		pPrev = p;
		pNext = p->pNext;
		p->pNext = this;
		pNext->pPrev = this;
	//}
	/*else
	{
		pNext = p;
		pPrev = p->pPrev;
		p->pPrev = this;
		pPrev->pNext = this;
	}
	*/
	
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
}
