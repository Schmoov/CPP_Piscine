#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}
AMateria::~AMateria() {}

const std::string& AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {(void) target;};
