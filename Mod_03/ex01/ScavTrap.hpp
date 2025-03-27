#pragma once
#include "ClapTrap.hpp"
#include <string>

class ScavTrap: public ClapTrap {
public:
	ScavTrap();
	ScavTrap(const ScavTrap& c);
	ScavTrap(const std::string& name);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& c);
	void attack(const std::string& target);
	void guardGate();
};


