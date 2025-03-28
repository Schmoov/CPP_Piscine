#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cerr << "Built default Dog \"" << type << "\"" << std::endl;
}

Dog::Dog(const Dog& a) : Animal(a)
{
	std::cerr << "Built Dog copy of \"" << a.type << "\"" << std::endl;
}

Dog& Dog::operator=(const Dog& a)
{
	if (this != &a)
		Animal::operator=(a);
	return *this;
}

Dog::~Dog()
{
	std::cerr << "Destroyed Dog \"" << type << "\"" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
