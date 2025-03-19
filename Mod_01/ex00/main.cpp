#include "Zombie.hpp"

int main()
{
	std::string sName("Stacky");
	Zombie s(sName);

	Zombie* heap = newZombie("Hippy");

	randomChump("Nesty");

	heap->announce();
	s.announce();

	std::cout << "Hippy and Stacky are still alive\n";
	delete heap;
	std::cout << "Only Stacky left\n";
}

