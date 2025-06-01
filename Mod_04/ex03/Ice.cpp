#include <iostream>
#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice") {};
Ice::Ice(const Ice& other) : AMateria("ice") {};
Ice& Ice::operator=(const Ice& other) {return *this;}
Ice::~Ice() {};

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "'* shoots an ice bolt at " << target.getName() << " *'\n";
}
