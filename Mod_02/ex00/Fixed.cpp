#include "Fixed.hpp"
#include <iostream>

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
