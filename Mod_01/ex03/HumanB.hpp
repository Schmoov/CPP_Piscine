#pragma once
#include "Weapon.hpp"

class HumanB {
public :
	HumanB(std::string& n);
	void attack();
	void setWeapon(Weapon& w);
private :
	const std::string& name;
	Weapon* weapon;
};
