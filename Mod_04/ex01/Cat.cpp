#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	type = "Cat";
	brain = new Brain;
	std::cerr << "Built default Cat \"" << type << "\"" << std::endl;
}

Cat::Cat(const Cat& a) : Animal(a)
{
	brain = new Brain;
	brain = a.brain;
	std::cerr << "Built Cat copy of \"" << a.type << "\"" << std::endl;
}

Cat& Cat::operator=(const Cat& a)
{
	brain = new Brain;
	brain = a.brain;
	if (this != &a)
		Animal::operator=(a);
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cerr << "Destroyed Cat \"" << type << "\"" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

void Cat::thinkOutLoud() const
{
	for (int i = 0; i < 100 && brain->ideas[i] != ""; i++)
		std::cout << brain->ideas[i] << std::endl;
}
