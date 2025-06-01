#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

const std::string& AMateria::getType() const {
	return type;
}
