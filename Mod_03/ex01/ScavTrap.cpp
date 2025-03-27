#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cerr << "Built default ScavTrap\n";
	hp = 100;
	mp = 50;
	atk = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cerr << "Built ScavTrap \"" << name << "\"\n";
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
		std::cerr << "ScavTrap \"" << name
			<< "\" is too DEAD to attack\n";
	} else if (mp < 1) {
		std::cerr << "ScavTrap \"" << name
			<< "\" is too TIRED to attack\n";
	} else {
		mp--;
		std::cerr << "ScavTrap \"" << name
			<< "\" attacks \"" << target
			<< "\", causing " << atk << " points of damage!\n";
	}
}


void ScavTrap::takeDamage(unsigned int amount)
{
	hp = amount > static_cast<unsigned int>(hp) ? 0 : hp - amount;
	std::cerr << "ScavTrap \"" << name
		<< "\" took " << amount << " points of damage!\n";
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (hp < 1) {
		std::cerr << "ScavTrap \"" << name
			<< "\" is too DEAD to repair\n";
	} else if (mp < 1) {
		std::cerr << "ScavTrap \"" << name
			<< "\" is too TIRED to repair\n";
	} else {
		mp--;
		std::cerr << "ScavTrap \"" << name
			<< "\" repairs itself from " << hp
			<< " to " << hp+amount << " hit points !\n";
		hp+=amount;
	}
}
