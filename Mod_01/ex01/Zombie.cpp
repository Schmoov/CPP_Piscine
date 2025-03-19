#include "Zombie.hpp"

Zombie::Zombie(std::string& name) : name(name) {}

Zombie::~Zombie()
{
	std::cerr << "Destroying \"" << name << "\"\n";
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
