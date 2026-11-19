#include "stackl.hpp"

template <typename T>
Stack<T>::Stack(): head_(nullptr), size_(0){}

template <typename T>
Stack<T>::~Stack() {
	clear();
}

template <typename T>
void Stack<T>::push(const T& value) {
	Node* new_node = new Node{ value, head_ };
	head_ = new_node;
	++size_;
}
template <typename T>
void Stack<T>::pop() {
	if (size_ == 0) {
		throw std::out_of_range("Stack::pop: stack is empty");
	}
	Node* temp = head_;
	head_ = head_->next;
	delete temp;
	--size_;
}

template <typename T>
bool Stack<T>::isEmpty() const {
	return size_ == 0;
}

template <typename T>
T& Stack<T>::top() {
	if (size_ == 0) {
		throw std::out_of_range("Stack::top: stack is empty");
	}
	return head_->value;
}
template <typename T>
const T& Stack<T>::top() const{
	if (size_ == 0) {
		throw std::out_of_range("Stack::top (const): stack is empty");
	}
	return head_->value;
}
template <typename T>
void Stack<T>::clear(){
	while (head_ != nullptr) {
		Node* temp = head_;
		head_ = head_->next;
		delete temp;
	}
	size_ = 0;
}

template <typename T>
Stack<T>::Stack(const Stack& other) {
	head_ = nullptr;
	size_ = 0;
	Node* tail = nullptr;
	Node* other_cur = other.head_;
	while (other_cur != nullptr) {
		Node* new_node = new Node(other_cur->value, nullptr);
		if (head_ == nullptr) {
			head_ = new_node;
		}
		else {
			tail->next = new_node;
		}
		tail = new_node;
		other_cur = other_cur->next;
		++size_;
	}
}
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
	if (this == &other) {
		return *this;
	}
	clear();

	Node* tail = nullptr;
	Node* other_cur = other.head_;
	while (other_cur != nullptr) {
		Node* new_node = new Node{ other_cur->value, nullptr };
		if (head_ == nullptr) {
			head_ = new_node;
		}
		else {
			tail->next = new_node;
		}
		tail = new_node;
		other_cur = other_cur->next;
		++size_;
	}
	return *this;
}
template class Stack<int64_t>;
template class Stack<std::string>;
template class Stack<int>;
template class Stack<double>;
template class Stack<char>;

