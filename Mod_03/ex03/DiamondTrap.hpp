#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap: public ScavTrap, public FragTrap {
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap& c);
	DiamondTrap(const std::string& name);
	~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap& c);
	using ScavTrap::attack;
	void whoAmI();
};


