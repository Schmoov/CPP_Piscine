#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string& n)
	: name(n) {}

void HumanB::setWeapon(Weapon& w)
{
	weapon = &w;
}

void HumanB::attack()
{
	std::cout << name << " attacks with their "
		<< weapon->getType() << "\n";
}
