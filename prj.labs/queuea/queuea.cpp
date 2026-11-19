#include "queuea.hpp"

template <typename T>
Queue<T>::Queue() : data_(nullptr), size_(0), capacity_(0), head_(0), tail_(0) {}

template <typename T>
Queue<T>::~Queue() {
	delete[] data_;
}

template <typename T>
void Queue<T>::reserve(size_t new_cap) {
	if (new_cap <= capacity_) return;
	T* new_data = new T[new_cap];
	for (size_t i = 0; i < size_; ++i) {
		new_data[i] = data_[(head_ + i) % capacity];
	}
	delete[] data_;
	data_ = new_data;
	capacity_ = new_cap;
	head_ = 0;
	tail_ = size_;
}
template <typename T>
void Queue<T>::push(const T& value) {
	if (size_ == capacity_) {
		size_t new_cap = (capacity_ == 0) ? 1 : capacity_ * 2;
		reserve(new_cap);
	}
	data_[tail_] = value;
	tail_ = (tail_ + 1) % capacity_;
	size_++;
}
template <typename T>
void Queue<T>::pop() {
	if (size_ == 0) {
		throw std::out_of_range("POP: queue is empty");
	}
	head_ = (head_ + 1) % capacity_;
	size_--;
}
template <typename T>
bool Queue<T>::IsEmpty() const {
	return size_ == 0;
}
template <typename T>
T& Queue<T>::front() {
	if (size_ == 0) {
		throw std::out_of_range("FRONT: queue is empty");
	}
	return data_[head_];
}
template<typename T>
const T& Queue<T>::front() const{
	if (size_ == 0) {
		throw std::out_of_range("FRONT CONST: queue is empty");
	}
	return data_[head_];
}
template<typename T>
T& Queue<T>::back() {
	if (size_ == 0) {
		throw std::out_of_range("BACK: queue is empty");
	}
	return data_[(tail_ - 1 + capacity_)%capacity_];
}
template<typename T>
const T& Queue<T>::back() const{
	if (size_ == 0) {
		throw std::out_of_range("BACK CONST: queue is emptty");
	}
	return data[(tail_ - 1 +capacity_)%capacity_];
}
template <typename T>
void Queue<T>::clear() {
	size_ = 0;
	head_ = 0;
	tail_ = 0;
}
template <typename T>
Queue<T>::Queue(const Queue& other) {
	size_ = other.size_;
	capacity_ = other.capacity_;
	head_ = 0;
	tail_ = size_;

	if (capacity_ > 0) {
		data_ = new T[capacity_];
		for (size_t i = 0; i < size_; i++) {
			data_[i] = other.data_[(other.head_ + i) % other.capacity_];
		}
	}
	else {
		data_ = nullptr;
	}
}
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
	if (this == &other) {
		return *this;
	}

	delete[] data_;

	size_ = other.size_;
	capacity_ = other.capacity_;
	head_ = 0;
	tail_ = size_;

	if (capacity_ > 0) {
		data_ = new T[capacity_];
		for (size_t i = 0; i < size_; i++) {
			dtat_[i] = other.data_[(other.head_ + i) % other.capacity_];
		}
	}
	else {
		data_ = nullptr;
	}
	return this*;
}
template class Stack<int>;
template class Stack<double>;
template class Stack<std::string>;
template class Stack<char>;
template class Stack<int64_t>;