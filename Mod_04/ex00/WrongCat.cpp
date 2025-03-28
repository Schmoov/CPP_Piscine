#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cerr << "Built default WrongCat \"" << type << "\"" << std::endl;
}

WrongCat::WrongCat(const WrongCat& a) : WrongAnimal(a)
{
	std::cerr << "Built WrongCat copy of \"" << a.type << "\"" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& a)
{
	if (this != &a)
		WrongAnimal::operator=(a);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cerr << "Destroyed WrongCat \"" << type << "\"" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
