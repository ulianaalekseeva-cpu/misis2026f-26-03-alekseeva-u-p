#include "stack.hpp"
template <typename T>
Stack<T>::Stack() :data_(nullptr), size_(0), capacity_(0) {}
template <typename T>
Stack<T>::~Stack() {
	delete[] data_;
}
template <typename T>
void Stack<T>::reserve(size_t new_cap) {
	if (new_cap <= capacity_) {
		return; //если памяти хватает, то выходим
	}
	T* new_data = new T[new_cap]; //выделяем масссив нужного размера
	for (size_t i = 0; i < size_; ++i) {
		new_data[i] = data_[i];
	}//копируем старые элементы в новый массив
	delete[] data_;//освобождаем память
	data_ = new_data;//обновили указатель
	capacity_ = new_cap;//обновили емкость

}
template <typename T>
void Stack<T>::push(const T& value) {
	if (size_ == capacity_) {//если нет места, то расширяем
		size_t new_cap = (capacity_ == 0) ? 1 : capacity_ * 2; //если capcity_ ==0, то берем 1, иначе удваиваем
		reserve(new_cap);
	}
	data_[size_] = value; //кладем элемент
	++size_; //увеличиваем размер
}
template <typename T>
void Stack<T> ::pop() {
	if (size_ == 0) {
		throw std::out_of_range("Stack::pop: stack is empty");
	}
	--size_;//уменьшаем размер

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
	return data_[size_ - 1];//верхний элемент это size_-1
}
template <typename T>
const T& Stack<T>::top() const {
	if (size_ == 0) {
		throw std::out_of_range("Stack::top(const): stack is empty");
	}
	return data_[size_ - 1];
}
template <typename T>
void Stack<T>::clear() {
	size_ = 0;
}
template <typename T>
Stack<T>::Stack(const Stack& other) {
	size_ = other.size_;
	capacity_ = other.capacity_;
	if (capacity_ > 0) {
		data_ = new T[capacity_];
		for (size_t i = 0; i < size_; ++i) {
			data_[i] = other.data_[i];
		}
	}
	else {
		data_ = nullptr;
	}
}
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
	if (this == &other) {
		return *this;
	}
	delete[] data_;
	size_ = other.size_;
	capacity_ = other.capacity_;

	if (capacity_ > 0) {
		data_ = new T[capacity_];
		for (size_t i = 0; i < size_; ++i) {
			data_[i] = other.data_[i];
		}
	}
	else {
		data_ = nullptr;
	}
	return *this;
}
template class Stack<int>;
template class Stack<double>;
template class Stack<std::string>;
template class Stack<char>;
template class Stack<int64_t>;
;

