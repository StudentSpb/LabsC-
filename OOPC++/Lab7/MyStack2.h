#pragma once
#include <iostream>

template <typename T> class MyStack2
{
	class Node
	{
	public:
		T data;
		Node* pNext;
		Node() : pNext(nullptr) {}
		explicit Node(T const& data) : data(data), pNext(nullptr) {}
	};

	Node* top;
	void print(Node* n);
	int count = 0;
public:
	MyStack2() : top(nullptr) {};
	void push(const T& x);
	T pop();
	void print();
	MyStack2(const MyStack2& other);
	MyStack2(MyStack2&& other);
	MyStack2& operator=(const MyStack2& other);
	MyStack2& operator=(MyStack2&& other);
};

template <typename T> MyStack2<T>::MyStack2(const MyStack2& other)
{
	top = nullptr;
	count = 0;
	if(other.count> 0)
	{
		Node* node = new Node(other.top->data);
		this->top = node;
		Node* tmp = other.top->pNext;
		while (tmp != nullptr)
		{
			node->pNext = new Node(tmp->data);
			node = node->pNext;
			tmp = tmp->pNext;
		}	
	}
}

template <typename T>
MyStack2<T>::MyStack2(MyStack2&& other)
{
	top = other.top;
	count = other.count;
	other.top = nullptr;
	other.count = 0;
}

template <typename T> MyStack2<T>& MyStack2<T>::operator=(const MyStack2& other)
{
	if (top != other.top)
	{
		Node* n = top;
		Node* tmp = other.top;
		if (count >= other.count)
		{
			for (int j = 0; j < count - other.count; j++)
			{
				n = n->pNext;
			}
			int count = (this->count < other.count) ? this->count : other.count;
			for (int i = 0; i < count; i++)
			{
				n->data = tmp->data;
				n = n->pNext;
				tmp = tmp->pNext;
			}
			int cnt = this->count;
			for (int i = count; i < cnt; i++)
			{
				pop();
			}
		}
		else
		{
			for (int j = 0; j < other.count- count; j++)
			{
				tmp = tmp->pNext;
			}
			int count = (this->count < other.count) ? this->count : other.count;
			for (int i = 0; i < count; i++)
			{
				n->data = tmp->data;
				n = n->pNext;
				tmp = tmp->pNext;
			}
			int index = 1;
			for (int i = count; i < other.count; i++)
			{
				tmp = other.top;
				for (int j = count; j < other.count - index; j++)
				{
					tmp = tmp->pNext;
				}
				push(tmp->data);
				index++;
			}
		}
	}
	return *this;
}

template <typename T>
MyStack2<T>& MyStack2<T>::operator=(MyStack2&& other)
{
	count = other.count;
	other.count = 0;
	top = other.top;
	other.top = nullptr;
	return *this;
}

template <typename T> void MyStack2<T>::push(const T& x)
{
	Node* n = new Node(x);
	n->pNext = top;
	top = n;
	count++;
}


template <typename T> T MyStack2<T>::pop()
{
	T tmp = top->data;
	top = top->pNext;
	count--;
	return tmp;
}


template <typename T> void MyStack2<T>::print()
{
	print(top);
	std::cout << std::endl << std::endl;
}


template <typename T> void MyStack2<T>::print(Node* node) 
{
	if (node == nullptr) return;
	print(node->pNext);
	std::cout << node->data << "    ";
}