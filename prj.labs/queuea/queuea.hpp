#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class Queue {
public:
	Queue();
	~Queue();
	Queue(const Queue& other);
	Queue& operator=(const Queue& other);
	void push(const T& value);
	void pop();
	bool IsEmpty() const;
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	void clear();
private:
	T* data_;
	size_t size_;
	size_t capacity_;
	size_t head_;
	size_t tril_;
	void reserve(size_t new_cap);
};