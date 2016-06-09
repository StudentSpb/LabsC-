#pragma once

class Counter
{
private:
	char* m_pStr;
	size_t m_nOwners;
	Counter* pNext;

	Counter(const char* p = " ");
	void AddString();
	void RemoveString();
	~Counter();

	static unsigned int m_curCounters;
	static Counter* pHead;

	static Counter* CreateCounter(const char* p);

	static void Print();
	static void ToUp();
	static void ToLow();
	static void PrintToAlph();

	friend class MyString;
};
