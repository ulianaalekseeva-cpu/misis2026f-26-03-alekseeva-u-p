#include <iostream>
#include <cstdint>
#include "stackl.hpp"

int main() {
	std::cout << "--- Testing List Stack ---" << std::endl;

	Stack<int64_t> s;
	s.push(10);
	s.push(20);
	s.push(30);

	std::cout << "Top: " << s.top() << " (expect 30)" << std::endl;

	s.pop();
	std::cout << "Top after pop: " << s.top() << " (expect 20)" << std::endl;

	// Проверка копирования
	Stack<int64_t> s2 = s;
	s2.push(99);
	std::cout << "s top: " << s.top() << " (expect 20)" << std::endl;
	std::cout << "s2 top: " << s2.top() << " (expect 99)" << std::endl;

	// Проверка присваивания
	Stack<int64_t> s3;
	s3 = s2;
	std::cout << "s3 top: " << s3.top() << " (expect 99)" << std::endl;

	// Очистка
	s.clear();
	std::cout << "s isEmpty after clear: " << s.isEmpty() << " (expect 1)" << std::endl;

	return 0;
}