#include "rational.h"
#include <numeric>
#include <stdexcept>

Rational::Rational() : num_(0), den_(1) {}
Rational::Rational(int num) : num_(num), den_(1) {}

Rational::Rational(int num, int den) {
	if (den == 0) {
		throw std::invalid_argument("Denominator cannot be zero!");
	}
	num_ = num;
	den_ = den;
	normalize();
}

int Rational::num() const { return num_; }
int Rational::den() const { return den_; }

void Rational::normalize() {
	if (den_ < 0) {
		num_ = -num_;
		den_ = -den_;
	}
	int g = std::gcd(num_, den_);
	if (g != 0) {
		num_ /= g;
		den_ /= g;
	}
}

//Операторы сравнения
bool Rational::operator==(const Rational& rhs) const {
	return num_ == rhs.num_ && den_ == rhs.den_;
}
bool Rational::operator!=(const Rational& rhs) const {
	return !(*this == rhs);
}
bool Rational::operator<(const Rational& rhs) const {
	return (long long)num_ * rhs.den_ < (long long)rhs.num_ * den_;
}
bool Rational::operator<=(const Rational& rhs) const {
	return *this < rhs || *this == rhs;
}
bool Rational::operator>(const Rational& rhs) const {
	return rhs < *this;
}
bool Rational::operator>=(const Rational& rhs) const {
	return rhs <= *this;
}

//Ариффметика с дробями
Rational& Rational::operator+=(const Rational& rhs) {
	long long n = (long long)num_ * rhs.den_ + (long long)rhs.num_ * den_;
	long long d = (long long)den_ * rhs.den_;
	num_ = (int)n; den_ = (int)d;
	normalize();
	return *this;
}
Rational& Rational::operator-=(const Rational& rhs) {
	long long n = (long long)num_ * rhs.den_ - (long long)rhs.num_ * den_;
	long long d = (long long)den_ * rhs.den_;
	num_ = (int)n; den_ = (int)d;
	normalize();
	return *this;
}
Rational& Rational::operator*=(const Rational& rhs) {
	long long n = (long long)num_ * rhs.num_;
	long long d = (long long)den_ * rhs.den_;
	num_ = (int)n; den_ = (int)d;
	normalize();
	return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
	if (rhs.num_ == 0) throw std::invalid_argument("Division by zero!");
	long long n = (long long)num_ * rhs.den_;
	long long d = (long long)den_ * rhs.num_;
	num_ = (int)n; den_ = (int)d;
	normalize();
	return *this;
}

//Арифметика с целыми числами
Rational& Rational::operator+=(int rhs) { return *this += Rational(rhs); }
Rational& Rational::operator-=(int rhs) { return *this -= Rational(rhs); }
Rational& Rational::operator*=(int rhs) { return *this *= Rational(rhs); }
Rational& Rational::operator/=(int rhs) { return *this /= Rational(rhs); }

//Вспомогательные методы
double Rational::to_double() const {
	return (double)num_ / den_;
}
Rational Rational::operator-() const {
	return Rational(-num_, den_);
}

// (Дробь и Дробь)
Rational operator+(const Rational& lhs, const Rational& rhs) { Rational res = lhs; res += rhs; return res; }
Rational operator-(const Rational& lhs, const Rational& rhs) { Rational res = lhs; res -= rhs; return res; }
Rational operator*(const Rational& lhs, const Rational& rhs) { Rational res = lhs; res *= rhs; return res; }
Rational operator/(const Rational& lhs, const Rational& rhs) { Rational res = lhs; res /= rhs; return res; }

//(Дробь и Целое)
Rational operator+(const Rational& lhs, int rhs) { return lhs + Rational(rhs); }
Rational operator-(const Rational& lhs, int rhs) { return lhs - Rational(rhs); }
Rational operator*(const Rational& lhs, int rhs) { return lhs * Rational(rhs); }
Rational operator/(const Rational& lhs, int rhs) { return lhs / Rational(rhs); }

//(Целое и Дробь)
Rational operator+(int lhs, const Rational& rhs) { return Rational(lhs) + rhs; }
Rational operator-(int lhs, const Rational& rhs) { return Rational(lhs) - rhs; }
Rational operator*(int lhs, const Rational& rhs) { return Rational(lhs) * rhs; }
Rational operator/(int lhs, const Rational& rhs) { return Rational(lhs) / rhs; }

//Потоки ввода/вывода
std::ostream& operator<<(std::ostream& os, const Rational& r) {
	os << r.num() << "/" << r.den();
	return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
	int n = 0, d = 1;
	char slash = 0;
	if (is >> n >> slash >> d) {
		if (slash != '/') {
			is.setstate(std::ios_base::failbit);
		}
		else if (d == 0) {
			is.setstate(std::ios_base::failbit);
		}
		else {
			r = Rational(n, d);
		}
	}
	return is;
}
