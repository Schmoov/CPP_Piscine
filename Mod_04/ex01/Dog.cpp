#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	type = "Dog";
	brain = new Brain;
	idea_nb = 0;
	std::cerr << "Built default Dog \"" << type << "\"" << std::endl;
}

Dog::Dog(const Dog& a) : Animal(a)
{
	brain = new Brain(*a.brain);
	idea_nb = a.idea_nb;
	std::cerr << "Built Dog copy of \"" << a.type << "\"" << std::endl;
}

Dog& Dog::operator=(const Dog& a)
{
	brain = new Brain;
	brain = a.brain;
	idea_nb = a.idea_nb;
	if (this != &a)
		Animal::operator=(a);
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cerr << "Destroyed Dog \"" << type << "\"" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

void Dog::thinkOutLoud() const
{
	for (int i = 0; i < 100 && brain->ideas[i] != ""; i++)
		std::cout << brain->ideas[i] << std::endl;
}

void Dog::brainWash(const std::string& newIdea)
{
	if (idea_nb == 100)
		std::cout << "Doggos ain't that smart\n";
	else
		brain->ideas[idea_nb++] = newIdea;
}
