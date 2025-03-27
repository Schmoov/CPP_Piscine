#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap c("Clappy");
	FragTrap s("Fraggy");

	//c.highFivesGuys();
	s.highFivesGuys();

	s.attack("Ennemy");
	s.takeDamage(5);
	s.beRepaired(1);
	for (int i = 0; i < 10; i++)
		s.beRepaired(0);
	s.attack("Ennemy");
}
