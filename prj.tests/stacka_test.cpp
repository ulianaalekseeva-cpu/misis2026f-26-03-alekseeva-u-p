#include <iostream>
#include <cstdint>
#include "stack.hpp"

int main() {
	std::cout << "--- Testing Stack ---" << std::endl;

	Stack<int64_t> s;
	s.push(10);
	s.push(20);
	s.push(30);

	std::cout << "Top: " << s.top() << std::endl; // Ожидаем 30

	s.pop();
	std::cout << "Top after pop: " << s.top() << std::endl; // Ожидаем 20

	// Проверка копирования
	Stack<int64_t> s2 = s;
	s2.push(99);

	std::cout << "s top: " << s.top() << std::endl;   // 20
	std::cout << "s2 top: " << s2.top() << std::endl; // 99

	// Проверка присваивания
	Stack<int64_t> s3;
	s3 = s2;
	std::cout << "s3 top: " << s3.top() << std::endl; // 99

	// Очистка
	s.clear();
	std::cout << "s isEmpty after clear: " << s.isEmpty() << std::endl; // 1

	// Обработка исключения
	try {
		s.pop();
	}
	catch (const std::out_of_range& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}