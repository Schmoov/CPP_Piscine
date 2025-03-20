#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(const std::string& n, Weapon& w)
	: name(n), weapon(w) {}

void HumanA::attack()
{
	std::cout << name << " attacks with their "
		<< weapon.getType() << "\n";
}
