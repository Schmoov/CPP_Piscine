#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap()
{
	std::cerr << "Built default ClapTrap\n";
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hp(10), mp(10), atk(0)
{
	std::cerr << "Built ClapTrap \"" << name << "\"\n";
}

ClapTrap::ClapTrap(const ClapTrap& c) : name(c.name), hp(c.hp), mp(c.mp), atk(c.atk)
{
	std::cerr << "Built a copy of ClapTrap \"" << name << "\"\n";
}

ClapTrap::~ClapTrap()
{
	std::cerr << "Destroyed ClapTrap \"" << name << "\"\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c)
{
	if (this != &c) {
		name = c.name;
		hp = c.hp;
		mp = c.mp;
		atk = c.atk;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (hp < 1) {
		std::cerr << "ClapTrap \"" << name
			<< "\" is too DEAD to attack\n";
	} else if (mp < 1) {
		std::cerr << "ClapTrap \"" << name
			<< "\" is too TIRED to attack\n";
	} else {
		mp--;
		std::cerr << "ClapTrap \"" << name
			<< "\" attacks \"" << target
			<< "\", causing " << atk << " points of damage!\n";
	}
}


void ClapTrap::takeDamage(unsigned int amount)
{
	hp = amount > static_cast<unsigned int>(hp) ? 0 : hp - amount;
	std::cerr << "ClapTrap \"" << name
		<< "\" took " << amount << " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hp < 1) {
		std::cerr << "ClapTrap \"" << name
			<< "\" is too DEAD to repair\n";
	} else if (mp < 1) {
		std::cerr << "ClapTrap \"" << name
			<< "\" is too TIRED to repair\n";
	} else {
		mp--;
		std::cerr << "ClapTrap \"" << name
			<< "\" repairs itself from " << hp
			<< " to " << hp+amount << " hit points !\n";
		hp+=amount;
	}
}
