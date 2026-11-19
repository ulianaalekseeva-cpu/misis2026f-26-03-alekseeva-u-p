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
	size_t size_;
	struct Node {
		T value;
		Node* next;
	};
	Node* head_;

};