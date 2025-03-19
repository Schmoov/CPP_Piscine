#include <string>
#include <iostream>

class Zombie {
private :
	const std::string name;
public :
	Zombie(std::string& name);
	~Zombie();
	void announce();
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);
