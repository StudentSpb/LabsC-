#pragma once
#include <ostream>
#include <iostream>


template <typename T> class MyQueue
{
	int capacity;
	int size;
	int first;
	int last;
	T* queue;
public:
	MyQueue(int = 3);
	~MyQueue() { delete[] queue; };
	void push(const T& x);
	T pop();
	void print();
	MyQueue(const MyQueue& other);
	MyQueue(MyQueue&& other);
	MyQueue& operator=(const MyQueue& other);
	MyQueue& operator=(MyQueue&& other);
};




template <typename T> MyQueue<T>::MyQueue(int i) : capacity(i), size(0), first(0), last(0), queue(new T[capacity]) {}




template <typename T> void MyQueue<T>::push(const T& x)
{
	if (size == capacity)
	{
		capacity = capacity + 3;
		T* tmp = new T[capacity];
		int i = first;
		for (int j = 0; j < size; j++)
		{
			tmp[j] = queue[i];
			i = (i + 1) % capacity;
		}
		delete queue;
		queue = tmp;
		first = 0;
		last = size;
	}
	queue[last] = x;
	last = (last + 1) % capacity;
	size++;
}



template <typename T> T MyQueue<T>::pop()
{
	if (size != 0)
	{
		T tmp = queue[first];
		first = (first + 1) % capacity;
		size--;
		return tmp;
	}
	return {};
}


template <typename T> void MyQueue<T>::print()
{
	for (int i = 0; i < size; i++) 
	{
		int m = (first + i) % capacity;
		std::cout << queue[m] << "     ";
	}
	std::cout << std::endl;
}



template<typename T> MyQueue<T>::MyQueue(const MyQueue& other) : capacity(other.size), size(other.size), first(0), last(other.size)
{
	//Проверять на пустую очередь
	queue = nullptr;
	if(other.size > 0)
	{
		queue = new T[size];
		for (int i = 0; i < size; i++)
		{
			int m = (other.first + i) % other.capacity;
			queue[i] = other.queue[m];
		}
	}
}

template <typename T>
MyQueue<T>::MyQueue(MyQueue&& other)
{
	if(other.size > 0)
	{
		first = other.first;
		size = other.size;
		capacity = other.size;
		last = other.last;
		queue = other.queue;
		other.queue = nullptr;
	}
	return *this;
}

template <typename T> MyQueue<T>& MyQueue<T>::operator=(const MyQueue& other)
{
	if (this != &other)
	{
		if (size < other.size)
		{
			delete[] queue;
			capacity = other.size;
			queue = new T[capacity];
		}
		size = other.size;
		for (int i = 0; i < size; i++)
		{
			int m = (other.first + i) % other.capacity;
			queue[i] = other.queue[m];
		}
	}
	return *this;
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(MyQueue&& other)
{
	if (other.size > 0)
	{
		first = other.first;
		size = other.size;
		capacity = other.size;
		last = other.last;
		queue = other.queue;
		other.queue = nullptr;
	}
	return *this;
}
