#include <iostream>
#include <iomanip>
#include "complex.hpp"

int main() {
	std::cout << std::fixed << std::setprecision(2); //выводит 2 числа после за€птой
	Complex a(2.0, 3.0);
	Complex b(3.0, 4.0);
	std::cout << "a:" << " " << a << std::endl;
	std::cout << "a + 5.0 =  " << a + 5.0 << std::endl;
	std::cout << "5.0 + a = " << 5.0 + a << std::endl;
	std::cout << "2.0 * a = " << 2.0 * a << std::endl;
	std::cout << "a * 2.0 = " << a *2.0 << std::endl;
	std::cout << "a - 2.0 = " << a - 2.0 << std::endl;
	std::cout << "a / 2.0 = " << a / 2.0 << std::endl;
	std::cout << "2.0 - a = " << 2.0 * a << std::endl;
	std::cout << "2.0 / a = " << 2.0 * a << std::endl;
	std::cout << "a+b = " << a + b << std::endl;
	std::cout << "a-b = " << a - b << std::endl;
	std::cout << "a*b = " << a * b << std::endl;
	std::cout << "a/b = " << a / b << std::endl;
	Complex c = a + b;
	std::cout << "a+=b = " << c << std::endl;
	c = a - b;
	std::cout << "a-=b = " << c << std::endl;
	c = a * b;
	std::cout << "a*=b = " << c << std::endl;
	c = a/b;
	std::cout << "a/=b = " << c << std::endl;
	return 0;
}
