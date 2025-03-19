#include "Zombie.hpp"

int main()
{
	Zombie* littleHorde = zombieHorde(1, "Remi");
	Zombie* bigHorde = zombieHorde(7, "Clony");
	littleHorde[0].announce();
	for (int i = 0; i < 7; i++)
		bigHorde[i].announce();
	delete[] bigHorde;
	delete[] littleHorde;
}

