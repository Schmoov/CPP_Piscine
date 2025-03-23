#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string& name) : name(name) {}
Zombie::Zombie() : name("Undefined") {}

Zombie::~Zombie()
{
	std::cerr << "Destroying \"" << name << "\"\n";
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
