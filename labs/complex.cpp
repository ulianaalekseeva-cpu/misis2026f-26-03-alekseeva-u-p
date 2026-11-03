#include "complex.hpp"
#include <cmath>

Complex::Complex() {
	real = 0.0;
	imag = 0.0;
}

Complex::Complex(double r, double i) {
	real = r;
	imag = i;
}

Complex Complex::operator+(const Complex& other) const {
	return Complex(real + other.real, imag + other.imag);
}
Complex Complex::operator-(const Complex& other)const {
	return Complex(real - other.real, imag - other.imag);
}
Complex Complex::operator*(const Complex & other)const {
	double new_real = (real * other.real) - (imag * other.imag);
	double new_imag = (real * other.imag) + (imag * other.real);
	return Complex(new_real, new_imag);
}
Complex Complex::operator/(const Complex& other)const {
	double denominator = (other.real * other.real) + (other.imag * other.imag);
	double new_real = ((real * other.real) + (imag * other.imag)) / denominator;
	double new_imag = ((imag * other.real) - (real * other.imag)) / denominator;
	return Complex(new_real, new_imag);
}
Complex& Complex::operator+=(const Complex& other) {
	*this = *this + other;
	return *this;
}
Complex& Complex::operator-=(const Complex& other) {
	*this = *this - other;
	return *this;
}
Complex& Complex::operator*=(const Complex& other) {
	*this = *this * other;
	return *this;
}
Complex& Complex::operator/=(const Complex& other) {
	*this = *this / other;
	return *this;
}

const double EPS = 1.0e-9;

bool Complex::operator==(const Complex& other)const {
	return(std::abs(real - other.real) < EPS) && (std::abs(imag - other.imag) < EPS);
}
bool Complex::operator!=(const Complex& other)const {
	return !(*this == other);
}
Complex Complex::operator-()const {
	return Complex(-real, -imag);
}
double Complex::operator[](int index) const {
	if (index == 0) return real;
	if (index == 1) return imag;
	return 0.0;
}
std::ostream& operator<<(std::ostream& os, const Complex& c) {
	os << c.real;
	if (c.imag >= 0) os << " + ";
	else os << " - ";
	os << (c.imag >= 0 ? c.imag : -c.imag) << "i";
	return os;
}
//complex operator double
Complex Complex::operator+(double rhs) const {
	return Complex(real + rhs, imag); 
}
Complex Complex::operator-(double rhs) const {
	return Complex(real - rhs, imag);
}
Complex Complex::operator*(double rhs) const {
	return Complex(real * rhs, imag*rhs);
}
Complex Complex::operator/(double rhs) const {
	return Complex(real / rhs, imag/rhs);
}
//double operator complex
Complex operator+(double lhs, const Complex& rhs) {
	return Complex(lhs + rhs.real, rhs.imag);
}
Complex operator-(double lhs, const Complex& rhs) {
	return Complex(lhs - rhs.real, -rhs.imag);
}
Complex operator*(double lhs, const Complex& rhs) {
	return Complex(lhs * rhs.real, lhs * rhs.imag);
}
Complex operator/(double lhs, const Complex& rhs) {
	double denominator = (rhs.real * rhs.real) + (rhs.imag * rhs.imag);
	return Complex((lhs * rhs.real) / denominator , (-lhs*rhs.imag)/denominator);
}
Complex Complex::operator+=(double rhs) {
	real += rhs;
	return *this;
}
Complex Complex::operator-=(double rhs) {
	real -= rhs;
	return *this;
}
Complex Complex::operator*=(double rhs) {
	real *= rhs;
	imag *= rhs;
	return *this;
}
Complex Complex::operator/=(double rhs) {
	real /= rhs;
	imag /= rhs;
	return *this;
}



