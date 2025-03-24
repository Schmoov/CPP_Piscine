#pragma once
#include <string>

class ClapTrap {
private:
	std::string name;
	int hp;
	int mp;
	int atk;

public:
	ClapTrap();
	ClapTrap(const ClapTrap& c);
	ClapTrap(const std::string& name);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& c);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


