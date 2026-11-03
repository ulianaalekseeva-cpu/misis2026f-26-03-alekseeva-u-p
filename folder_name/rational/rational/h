#pragma once
#include <iostream>

class Rational {
private:
	int num_; 
	int den_; 
	void normalize(); 

public:
	Rational();
	Rational(int num);
	Rational(int num, int den);

	int num() const;
	int den() const;

	// Операторы сравнения
	bool operator==(const Rational& rhs) const;
	bool operator!=(const Rational& rhs) const;
	bool operator<(const Rational& rhs) const;
	bool operator<=(const Rational& rhs) const;
	bool operator>(const Rational& rhs) const;
	bool operator>=(const Rational& rhs) const;

	// Операции с другими дробями
	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);

	// Операции с целыми числами 
	Rational& operator+=(int rhs);
	Rational& operator-=(int rhs);
	Rational& operator*=(int rhs);
	Rational& operator/=(int rhs);

	// Вспомогательные методы
	double to_double() const;
	Rational operator-() const; 
};

// Глобальные операторы: Дробь и Дробь
Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

// Глобальные операторы: Дробь и Целое
Rational operator+(const Rational& lhs, int rhs);
Rational operator-(const Rational& lhs, int rhs);
Rational operator*(const Rational& lhs, int rhs);
Rational operator/(const Rational& lhs, int rhs);

// Глобальные операторы: Целое и Дробь
Rational operator+(int lhs, const Rational& rhs);
Rational operator-(int lhs, const Rational& rhs);
Rational operator*(int lhs, const Rational& rhs);
Rational operator/(int lhs, const Rational& rhs);

// Потоки ввода-вывода
std::ostream& operator<<(std::ostream& os, const Rational& r);
std::istream& operator>>(std::istream& is, Rational& r);
