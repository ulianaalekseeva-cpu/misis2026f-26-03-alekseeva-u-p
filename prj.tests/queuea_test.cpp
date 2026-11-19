#include <iostream>
#include <cstdint>
#include "queuea.hpp"

int main() {
	std::cout << "--- Testing Queue ---" << std::endl;

	Queue<int64_t> q;
	q.push(10);
	q.push(20);
	q.push(30);

	std::cout << "Front: " << q.front() << " (expect 10)" << std::endl;
	std::cout << "Back: " << q.back() << " (expect 30)" << std::endl;

	q.pop();
	std::cout << "Front after pop: " << q.front() << " (expect 20)" << std::endl;

	q.push(40);
	q.push(50); 

	std::cout << "Back after push: " << q.back() << " (expect 50)" << std::endl;

	Queue<int64_t> q2 = q;
	q2.push(99);
	std::cout << "q back: " << q.back() << " (expect 50)" << std::endl;
	std::cout << "q2 back: " << q2.back() << " (expect 99)" << std::endl;

	q.clear();
	std::cout << "q isEmpty after clear: " << q.IsEmpty() << " (expect 1)" << std::endl;

	try {
		q.pop();
	}
	catch (const std::out_of_range& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}