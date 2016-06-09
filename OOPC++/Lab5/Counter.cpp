#include  "Counter.h"
#include <cstring>
#include <iostream>

Counter* Counter::pHead = nullptr;
unsigned int Counter::m_curCounters;

Counter::Counter(const char * p)
{
	size_t n = strlen(p) + 1;
	m_pStr = new char[n];
	strcpy(m_pStr, p);
	pNext = pHead;
	m_nOwners = 1;
	pHead = this;
}

void Counter::AddString()
{
	m_nOwners++;
}

void Counter::RemoveString()
{
	m_nOwners--;
	if(m_nOwners==0)
	{
		delete this;
	}
}

Counter::~Counter()
{
	Counter* p = pHead;
	while (p != nullptr)
	{
		Counter* pp = p->pNext;
		if (pp != nullptr)
		{
			if (this->m_pStr == pHead->m_pStr)
			{
				pHead = pNext;
				break;
			}
			if (this->m_pStr == pp->m_pStr)
			{
				p->pNext = pNext;
				break;
			}
		}
		p = pp;
	}
	m_curCounters--;
	delete[] m_pStr;

}

Counter * Counter::CreateCounter(const char * p)
{
	Counter *pH = pHead;
	while(pH != nullptr)
	{
		int res = strcmp(pH->m_pStr, p);
		if(res == 0)
		{
			pH->AddString();
			return pH;
		}
		pH = pH->pNext;
	}
	m_curCounters++;
	return new Counter(p);
}

void Counter::Print()
{
	Counter* p = pHead;
	while(p != nullptr)
	{
		std::cout << p->m_pStr << std::endl;
		p = p->pNext;
	}
}

void Counter::ToUp()
{
	Counter* p = pHead;
	while (p != nullptr)
	{
		strupr(p->m_pStr);
		p = p->pNext;
	}
}

void Counter::ToLow()
{
	Counter* p = pHead;
	while (p != nullptr)
	{
		strlwr(p->m_pStr);
		p = p->pNext;
	}
}

void Counter::PrintToAlph()
{
	//«аписать в массив, в нем отсортировать и вывести
	char** pStr = new char*[m_curCounters];
	Counter* p = pHead;
	for (int i = 0; i < m_curCounters;i++)
	{
		pStr[i] = p->m_pStr;
		p = p->pNext;
	}
	for (int j = 1; j<m_curCounters; j++)
	{
		for (int i = 1; i < m_curCounters;i++)
		{
			int res = strcmp(pStr[i - 1], pStr[i]);
			if (res > 0)
			{
				char* pCh = pStr[i];
				pStr[i] = pStr[i - 1];
				pStr[i - 1] = pCh;
			}
		}
	}
	for (int i = 0; i < m_curCounters;i++)
	{
		std::cout << pStr[i]<<std::endl; 
	}
	delete[] pStr;
}
