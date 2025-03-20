#pragma once
#include "Weapon.hpp"

class HumanA {
public :
	HumanA(char& n, Weapon& w);
	void attack();
private :
	const std::string& name;
	const Weapon& weapon;
};
