#include <iostream>
#include "rational.h"

int main() {
	Rational a(1, 2); // 1/2
	Rational b(1, 3); // 1/3

	// Сравнения
	std::cout << "1/2 < 1/3: " << (a < b) << std::endl;   
	std::cout << "1/2 >= 1/3: " << (a >= b) << std::endl; 

	// Арифметика с дробями
	cout << "1/2 + 1/3 = " << (a + b) << std::endl; 
	cout << "1/2 * 1/3 = " << (a * b) << endl; 

	// Арифметика с целыми (комбинированные операторы)
	Rational c(3, 4);
	c += 2;
	cout << "3/4 + 2 = " << c << endl; 

	c *= 3;
	cout << "11/4 * 3 = " << c << endl; 

	// Ввод-вывод
	cout << "Enter a fraction (e.g. 7/8): ";
	Rational d;
	cin >> d;
	if (cin) {
		cout << "You entered: " << d << endl;
		cout << "As double: " << d.to_double() << endl;
	}

	return 0;
}
