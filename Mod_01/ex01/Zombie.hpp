#pragma once
#include <string>

class Zombie {
private :
public :
	std::string name;
	Zombie();
	Zombie(std::string& name);
	~Zombie();
	void announce();
};

Zombie *zombieHorde(int N, std::string name);
