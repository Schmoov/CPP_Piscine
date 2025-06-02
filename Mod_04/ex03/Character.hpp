#pragma once
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
private:
	std::string name;
	AMateria* inv[4];
	int full;
	AMateria* garb[5000];
	int gI;
public:
	 Character();
	 Character(const Character& other);
	 Character& operator=(const Character& other);
	 Character(const std::string& name);
	 ~Character();
	 std::string const & getName() const;
	 void equip(AMateria* m);
	 void unequip(int idx);
	 void use(int idx, ICharacter& target);
};
