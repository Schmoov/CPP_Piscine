#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap d("Diamy");

	/*
	d.highFivesGuys();
	d.guardGate();
	d.whoAmI();

	d.attack("Ennemy");
	d.takeDamage(5);
	d.beRepaired(1);
	for (int i = 0; i < 10; i++)
		d.beRepaired(0);
	d.attack("Ennemy");
*/
	DiamondTrap cpy((d));
	cpy.whoAmI();
	DiamondTrap eq;
	eq = d;
	eq.whoAmI();
}
