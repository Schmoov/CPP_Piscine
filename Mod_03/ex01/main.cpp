#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap c("Clappy");
	ScavTrap s("Scavy");

	//c.guardGate();
	s.guardGate();

	s.attack("Ennemy");
	s.takeDamage(5);
	s.beRepaired(1);
	for (int i = 0; i < 10; i++)
		s.beRepaired(0);
	s.attack("Ennemy");

	ScavTrap cpy((s));
}
