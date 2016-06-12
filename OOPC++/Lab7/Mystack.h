#pragma once
#include <stdexcept>

template<typename T, int capacity = 5> class MyStack
{
private:
	int count = 0;
	T m_ar[capacity];
public:
	MyStack() = default;
	void push(const T& value);
	T pop();
	T& operator[](int i);
	int GetCount() const;
};


template <typename T, int capacity> T& MyStack<T, capacity>::operator[](int i)
{
	if (i >= 0 && i < count) 
		return m_ar[i];
	else 
		throw std::invalid_argument("Big argument");
}




template <typename T, int capacity> void MyStack<T, capacity>::push(const T &x)
{
	if (count < capacity)
	{
		m_ar[count] = x;
		count++;
	}
	else 
		throw std:: invalid_argument("Big argument");
}


template <class T, int i> T MyStack<T, i>::pop()
{
	count--;
	if (count > 0)
	{
		return m_ar[count];
	}
	else 
		throw std::invalid_argument("Error index");
}

template <typename T, int capacity> int MyStack<T, capacity>::GetCount() const
{
	return count;
}
