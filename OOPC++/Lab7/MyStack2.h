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

template <typename T>
MyStack2<T>::MyStack2(MyStack2&& other)
{
	Node* node = new Node(other.top->data);
	this->top = node;
	Node* tmp = other.top->pNext;
	other.top = nullptr;
	while (tmp != nullptr)
	{
		node->pNext = new Node(tmp->data);
		node = node->pNext;	
		auto nodeForDelete = tmp;
		tmp = tmp->pNext;
		nodeForDelete = nullptr;
	}
}

template <typename T> MyStack2<T>& MyStack2<T>::operator=(const MyStack2& other)
{
	if (top != other.top)
	{
		Node* n = top;
		Node* tmp = other.top;
/*
		while (count == other.count)
		{
			n->data = tmp->data;
			n = n->pNext;
			tmp = tmp->pNext;
		}
		if (tmp)
		{
			while (tmp)
			{
				n = new Node(tmp->data);
				n = n->pNext;
				tmp = tmp->pNext;
			}
		}
		else
		{
			while (n)
			{
				tmp = n->pNext;
				delete n;
				n = tmp;
			}
		}
		*/

		int count = (this->count < other.count) ? this->count : other.count;
		for (int i = 0; i < count; i++)
		{
			n->data = tmp->data;
			n = n->pNext;
			tmp = tmp->pNext;
		}

		for (int i = count; i< this->count; i++)
		{
			tmp = n->pNext;
			delete n;
			n = tmp;
		}


	}
	return *this;

}

template <typename T>
MyStack2<T>& MyStack2<T>::operator=(MyStack2&& other)
{
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