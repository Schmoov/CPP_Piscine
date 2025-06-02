#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() : full(0) {}
MateriaSource::~MateriaSource() {}
MateriaSource::MateriaSource(const MateriaSource& other)
: full(other.full) {
	for (int i = 0; i < 4; i++)
		if (full & (1 << i))
			inv[i] = other.inv[i]->clone();
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (&other != this) {
		full = other.full;
		for (int i = 0; i < 4; i++)
			if (full & (1 << i))
				inv[i] = other.inv[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!(full & (1 << i))) {
			full |= 1 << i;
			inv[i] = m->clone();
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; i++) {
		if (!(full & (1 << i)) && inv[i]->getType() == type) {
			return inv[i]->clone();
		}
	}
	return 0;
}

