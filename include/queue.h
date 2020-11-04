#pragma once

#include "vector.h"
#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;

template <typename T>
class Queue : public Vector<T>
{
private:
	unsigned int front;
	unsigned int back;
	void push_back(T elem) {}
	void pop_back() {}
	void push_front(T elem) {}
	void pop_front() {}
	void resize(int n) {}
	void insert(T elem, int index) {}
	void erase(int index) {}
public:
	Queue() : Vector() { front = 0; back = 0; }
	Queue(int n) : Vector(n) 
	{
		front = 0;
		back = n - 1; 
	}

	~Queue() {}

	void push(T elem) 
	{
		back++;
		if (back == capacity)
			back = 0;
		if (full())
			resize(size_t(2.0 * capacity));
		data[back] = elem;
		size++;
	}

	void pop() 
	{
		if (empty()) 
			throw "Smth wrong!";
		if (front == capacity)
			front = 0;
		else front++;
		size--;
	}

	bool empty() 
	{
		return size == 0;
	}

	bool full() 
	{
		return size == capacity;
	}
};
