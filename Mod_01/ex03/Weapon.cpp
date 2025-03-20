#include "Weapon.hpp"
#include <string>

Weapon::Weapon(const std::string& t) : type(t) {}
const std::string& Weapon::getType() const
{
	return type;
}

void Weapon::setType(std::string& newType)
{
	type = newType;
}
