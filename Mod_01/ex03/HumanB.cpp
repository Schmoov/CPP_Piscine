#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(const std::string& n)
	: name(n), weapon(NULL) {}

void HumanB::setWeapon(Weapon& w)
{
	weapon = &w;
}

void HumanB::attack()
{
	std::cout << name << " attacks with their "
		<< (weapon ? weapon->getType() : "bare hands") << "\n";
}
