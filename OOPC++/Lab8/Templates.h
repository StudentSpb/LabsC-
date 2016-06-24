#pragma once
#include <vector>
#include "Point.h"

using namespace std;

template<typename T> void printVector(const std::vector<T>& vect)
{
	cout << "Vector size: " << vect.size() << endl;
	cout << "Vector capacity: " << vect.capacity() << endl;
	cout << "Vector max size: " << vect.max_size() << endl;
	int s = vect.size();
	for (int i = 0; i < s; i++)
	{
		cout << vect[i] << " ";
	}
	cout << endl;
}

template<typename T> void printInfo(const T& cont)
{
	cout << "Container's type: " << typeid(cont).name() << endl;

	typename T::const_iterator first = cont.begin();
	typename T::const_iterator last = cont.end();
	while (first != last)
	{
		cout << *first << endl;
		++first;
	}
	cout << endl;
}

bool neg(const Point& tmp)
{
	return tmp.m_x < 0 || tmp.m_y < 0;
};
