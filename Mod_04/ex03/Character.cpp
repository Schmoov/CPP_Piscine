#include "Character.hpp"
#include "ICharacter.hpp"

Character::Character() : name("Unnamed"), full(0), gI(0) {}
Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (full & (1 << i))
			delete inv[i];
	for (int i = 0; i < gI; i++)
		delete garb[i];
}

Character::Character(const Character& other)
: name(other.name), full(other.full), gI(0) {
	for (int i = 0; i < 4; i++)
		if (full & (1 << i))
			inv[i] = other.inv[i]->clone();
}

Character& Character::operator=(const Character& other) {
	if (&other != this) {
		for (int i = 0; i < 4; i++)
			if (full & (1 << i))
				delete inv[i];
		for (int i = 0; i < gI; i++)
			delete garb[i];
		name = other.name;
		full = other.full;
		for (int i = 0; i < 4; i++)
			if (full & (1 << i))
				inv[i] = other.inv[i]->clone();
	}
	return *this;
}

Character::Character(const std::string& name) : name(name), full(0), gI(0) {}


const std::string& Character::getName() const {return name;}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!(full & (1 << i))) {
			full |= 1 << i;
			inv[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 4)
		return;
	if (full & (1 << idx)) {
		full ^= 1 << idx;
		garb[gI++] = inv[idx];
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 4)
		return;
	if (!(full & (1<<idx)))
		return;
	inv[idx]->use(target);

}
