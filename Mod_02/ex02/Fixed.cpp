#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
	: val(0)
{
	//std::cerr << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& a) : val(a.val)
{
	//std::cerr << "Copy constructor called\n";
}

Fixed::Fixed(const int n)
{
	//std::cerr << "Int constructor called\n";
	val = n << frac;
}

//Implicit casting like its nothing
Fixed::Fixed(const float n)
{
	//std::cerr << "Float constructor called\n";
	val = roundf(n * (1 << frac));
}

Fixed::~Fixed()
{
	//std::cerr << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& a)
{
	//std::cerr << "Copy assignment operator called\n";
	if (this != &a)
		val = a.val;
	return *this;
}

int Fixed::getRawBits() const
{
	//std::cerr << "getRawBits member function called\n";
	return val;
}

void Fixed::setRawBits(int const raw)
{
	//std::cerr << "setRawBits member function called\n";
	val = raw;
}

float Fixed::toFloat() const
{
	return static_cast<float>(val) / (1 << frac);
}

int Fixed::toInt() const
{
	return val >> frac;
}

std::ostream& operator<<(std::ostream& os, const Fixed& n)
{
	os << n.toFloat();
	return os;
}

//new

bool Fixed::operator>(const Fixed& n) const
{
	return val > n.val;
}

bool Fixed::operator<(const Fixed& n) const
{
	return val < n.val;
}

bool Fixed::operator>=(const Fixed& n) const
{
	return val >= n.val;
}

bool Fixed::operator<=(const Fixed& n) const
{
	return val <= n.val;
}

bool Fixed::operator==(const Fixed& n) const
{
	return val == n.val;
}

bool Fixed::operator!=(const Fixed& n) const
{
	return val != n.val;
}

Fixed Fixed::operator+(const Fixed& n) const
{
	Fixed res;
	int raw = getRawBits() + n.getRawBits();
	res.setRawBits(raw);
	return res;
}

Fixed Fixed::operator-() const
{
	Fixed res;
	int raw = -getRawBits();
	res.setRawBits(raw);
	return res;
}

Fixed Fixed::operator-(const Fixed& n) const
{
	Fixed res;
	int raw = getRawBits() - n.getRawBits();
	res.setRawBits(raw);
	return res;
}

//Minimize rounding errors on both ends would be
//int raw = (getRawBits()>>(frac/2)) * (n.getRawBits()>>(frac/2));
//subject seems more interested in small numbers
Fixed Fixed::operator*(const Fixed& n) const
{
	Fixed res;
	float calc = static_cast<float>(getRawBits()) * n.getRawBits();
	int raw = roundf(calc / (1<<frac));
	res.setRawBits(raw);
	return res;
}

//int raw = (getRawBits()<<frac) / n.getRawBits();
//this seems less precise than the float one
Fixed Fixed::operator/(const Fixed& n) const
{
	Fixed res;
	int raw = roundf((static_cast<float>(1<<frac)*getRawBits()) / n.getRawBits());
	res.setRawBits(raw);
	return res;
}

Fixed& Fixed::operator++()
{
	*this = *this + Fixed::epsilon;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed res = *this;
	*this = *this + Fixed::epsilon;
	return res;
}

Fixed& Fixed::operator--()
{
	*this = *this - Fixed::epsilon;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed res = *this;
	*this = *this - Fixed::epsilon;
	return res;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a<b?a:b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a<b?a:b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a>b?a:b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a>b?a:b;
}

const Fixed& Fixed::getEpsilon()
{
	static Fixed res;
	res.setRawBits(1);
	return res;
}

const Fixed Fixed::epsilon = Fixed::getEpsilon();
