#pragma once
#include "Weapon.hpp"

class HumanA {
public :
	HumanA(const std::string& n, Weapon& w);
	void attack();
private :
	const std::string& name;
	const Weapon& weapon;
};
