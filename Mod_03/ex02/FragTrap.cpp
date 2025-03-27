#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	std::cerr << "Built default FragTrap\n";
}

FragTrap::FragTrap(const std::string& n) : ClapTrap()
{
	std::cerr << "Built FragTrap \"" << n << "\"\n";
	name = n;
	hp = 100;
	mp = 100;
	atk = 30;
}

FragTrap::FragTrap(const FragTrap& c) : ClapTrap(c)
{
	std::cerr << "Built a copy of FragTrap \"" << name << "\"\n";
}

FragTrap::~FragTrap()
{
	std::cerr << "Destroyed FragTrap \"" << name << "\"\n";
}

FragTrap& FragTrap::operator=(const FragTrap& c)
{
	if (this != &c) {
		ClapTrap::operator=(c);
	}
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (hp < 1) {
		std::cerr << "FragTrap \"" << name
			<< "\" is too DEAD to attack\n";
	} else if (mp < 1) {
		std::cerr << "FragTrap \"" << name
			<< "\" is too TIRED to attack\n";
	} else {
		mp--;
		std::cerr << "FragTrap \"" << name
			<< "\" attacks \"" << target
			<< "\", causing " << atk << " points of damage!\n";
	}
}

void FragTrap::highFivesGuys()
{
	std::cerr << "FragTrap \"" << name << "\" requests high five (woohoo)\n";
}
