#include <iostream>

int main() {
	for (int year=2026; year < 9999; year += 1) {
		int a = year % 10;
		int b = (year / 10) % 10;
		int c = (year / 100) % 10;
		int d = year / 1000;
		if (a != b && a != c && a != d && b != c && b != d && c != d) {
			std::cout << year;
			break;
		}
	}
}
