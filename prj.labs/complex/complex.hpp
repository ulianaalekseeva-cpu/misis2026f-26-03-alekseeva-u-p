#include <iostream>
#pragma once

class Complex {
public:
	double real;
	double imag;
	Complex();
	Complex(double r, double i);
	friend std::ostream& operator<<(std::ostream& os, const Complex& c);

	Complex operator+(const Complex& other)const;
	Complex operator-(const Complex& other)const;
	Complex operator*(const Complex& other)const;
	Complex operator/(const Complex& other)const;
	Complex& operator+=(const Complex& other);
	Complex& operator-=(const Complex& other);
	Complex& operator*=(const Complex& other);
	Complex& operator/=(const Complex& other);
	bool operator==(const Complex& other) const;
	bool operator!=(const Complex& other) const;
	Complex operator-() const;
	double operator[](int index) const;
	Complex operator+(double rhs)const;
	Complex operator-(double rhs)const;
	Complex operator*(double rhs)const;
	Complex operator/(double rhs)const;	
	Complex operator+=(double rhs);
	Complex operator-=(double rhs);
	Complex operator*=(double rhs);
	Complex operator/=(double rhs);
};
Complex operator+(double lhs, const Complex& rhs);
Complex operator-(double lhs, const Complex& rhs);
Complex operator*(double lhs, const Complex& rhs);
Complex operator/(double lhs, const Complex& rhs);
