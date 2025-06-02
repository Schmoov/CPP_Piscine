#pragma once
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource {
private:
	AMateria* inv[4];
	int full;
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();

	void learnMateria(AMateria* m);
	AMateria* createMateria(const std::string& type);

};
