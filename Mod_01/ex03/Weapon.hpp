#pragma once
#include <string>

class Weapon {
public :
	Weapon(const std::string& w);
	const std::string& getType() const;
	void setType(std::string& newType);

private :
	std::string type;
};
