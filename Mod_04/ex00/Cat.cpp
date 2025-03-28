#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cerr << "Built default Cat \"" << type << "\"" << std::endl;
}

Cat::Cat(const Cat& a) : Animal(a)
{
	std::cerr << "Built Cat copy of \"" << a.type << "\"" << std::endl;
}

Cat& Cat::operator=(const Cat& a)
{
	if (this != &a)
		Animal::operator=(a);
	return *this;
}

Cat::~Cat()
{
	std::cerr << "Destroyed Cat \"" << type << "\"" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
