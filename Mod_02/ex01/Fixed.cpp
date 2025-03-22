#include "Fixed.hpp"
#include <iostream>
#include <climits>

/*
//Skill issue edition :
Fixed::Fixed(const Fixed& a)
{
	std::cerr << "Copy constructor called\n";
	*this = a;
}

Fixed& Fixed::operator=(const Fixed& a)
{
	std::cerr << "Copy assignment operator called\n";
	if (this != &a)
		val = a.getRawBits();
	return *this;
}
*/

Fixed::Fixed()
	: val(0)
{
	std::cerr << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& a) : val(a.val)
{
	std::cerr << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& a)
{
	std::cerr << "Copy assignment operator called\n";
	if (this != &a)
		val = a.val;
	return *this;
}

Fixed::~Fixed()
{
	std::cerr << "Destructor called\n";
}

int Fixed::getRawBits() const
{
	std::cerr << "getRawBits member function called\n";
	return val;
}

void Fixed::setRawBits(int const raw)
{
	std::cerr << "setRawBits member function called\n";
	val = raw;
}

//new
Fixed::Fixed(const int n)
{
	std::cerr << "Int constructor called\n";
	if (n > FIXED_MAX || n < FIXED_MIN)
		throw "overflow";
	val = n << frac;
}

Fixed::Fixed(const float n)
{
	std::cerr << "Float constructor called\n";
	if (n > FIXED_MAX || n < FIXED_MIN)
		throw "overflow";
	val = (int)(n * (1 << frac));
}

float Fixed::toFloat() const
{
	return val/(float)(1<<8);
}

int Fixed::toInt() const
{
	return val>>8;
}

std::ostream& operator<<(std::ostream& os, const Fixed& n)
{
	os << n.toFloat();
	return os;
}
