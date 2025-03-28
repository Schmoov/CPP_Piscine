#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cerr << "Built default Animal \"" << type << "\"" << std::endl;
}

Animal::Animal(const Animal& a) :type(a.type)
{
	std::cerr << "Built Animal copy of \"" << a.type << "\"" << std::endl;
}

Animal& Animal::operator=(const Animal& a)
{
	if (this != &a)
		type = a.type;
	return *this;
}

Animal::~Animal()
{
	std::cerr << "Destroyed Animal \"" << type << "\"" << std::endl;
}


void Animal::makeSound() const
{
	std::cout << "*Animal sounds*" << std::endl;
}

const std::string& Animal::getType() const
{
	return type;
}
