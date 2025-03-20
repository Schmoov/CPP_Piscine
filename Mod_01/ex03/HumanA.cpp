#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(char& n, Weapon& w)
	: name(n), weapon(w) {}

void HumanA::attack()
{
	std::cout << name << " attacks wiht their "
		<< weapon.getType() << "\n";
}
