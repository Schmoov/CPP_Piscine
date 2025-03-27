#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cerr << "Built default DiamondTrap\n";
}

DiamondTrap::DiamondTrap(const std::string& n) : ClapTrap()
{
	std::cerr << "Built DiamondTrap \"" << n << "\"\n";
	ClapTrap::name = n + "_clap_name";
	name = n;
	hp = 100;
	mp = 50;
	atk = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& c) : ClapTrap(c)
{
	name = c.name;
	std::cerr << "Built a copy of DiamondTrap \"" << c.name << "\"\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cerr << "Destroyed DiamondTrap \"" << name << "\"\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& c)
{
	if (this != &c) {
		ClapTrap::operator=(c);
		name = c.name;
	}
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "name is \"" << name
		<< "\" as a ClapTrap its \"" << ClapTrap::name << "\"\n";
}
