#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cerr << "Built default WrongAnimal \"" << type << "\"" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a) :type(a.type)
{
	std::cerr << "Built WrongAnimal copy of \"" << a.type << "\"" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a)
{
	if (this != &a)
		type = a.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cerr << "Destroyed WrongAnimal \"" << type << "\"" << std::endl;
}


void WrongAnimal::makeSound() const
{
	std::cout << "*WrongAnimal sounds*" << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return type;
}
