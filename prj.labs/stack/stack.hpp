#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class Stack {
public:
	Stack();
	~Stack();
	Stack(const Stack& other);
	Stack& operator=(const Stack& other);
	void push(const T& value);
	void pop();
	bool isEmpty() const;
	T& top();
	const T& top() const;
	void clear();
private:
	T* data_;
	size_t size_;
	size_t capacity_;
	void reserve(size_t new_cap);
};