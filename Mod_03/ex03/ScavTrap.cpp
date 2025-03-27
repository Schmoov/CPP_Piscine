#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cerr << "Built default ScavTrap\n";
}

ScavTrap::ScavTrap(const std::string& n) : ClapTrap()
{
	std::cerr << "Built ScavTrap \"" << n << "\"\n";
	name = n;
	hp = 100;
	mp = 50;
	atk = 20;
}

ScavTrap::ScavTrap(const ScavTrap& c) : ClapTrap(c)
{
	std::cerr << "Built a copy of ScavTrap \"" << name << "\"\n";
}

ScavTrap::~ScavTrap()
{
	std::cerr << "Destroyed ScavTrap \"" << name << "\"\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& c)
{
	if (this != &c) {
		ClapTrap::operator=(c);
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (hp < 1) {
		std::cout << "ScavTrap \"" << name
			<< "\" is too DEAD to attack\n";
	} else if (mp < 1) {
		std::cout << "ScavTrap \"" << name
			<< "\" is too TIRED to attack\n";
	} else {
		mp--;
		std::cout << "ScavTrap \"" << name
			<< "\" attacks \"" << target
			<< "\", causing " << atk << " points of damage!\n";
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap \"" << name << "\" is now in Gate keeper mode\n";
}
