#include "ClapTrap.hpp"

int main()
{
	ClapTrap c("Original name");

	c.attack("Ennemy");
	c.takeDamage(5);
	c.beRepaired(1);
	for (int i = 0; i < 10; i++)
		c.beRepaired(0);
	c.attack("Ennemy");
	c.beRepaired(100);

	ClapTrap d("Kenny");
	d.takeDamage(420);
	d.beRepaired(1000);
	d.attack("Ennemy");
}
