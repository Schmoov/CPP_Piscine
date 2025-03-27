#pragma once
#include "ClapTrap.hpp"
#include <string>

class FragTrap: virtual public ClapTrap {
public:
	FragTrap();
	FragTrap(const FragTrap& c);
	FragTrap(const std::string& name);
	~FragTrap();
	FragTrap& operator=(const FragTrap& c);
	void attack(const std::string& target);
	void highFivesGuys();
};


