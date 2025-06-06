#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{std::cerr << "Skill Issue\n";};
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& o)
	: AForm(o), target(o.target) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& o)
{(void) o; std::cerr << "Skill Issue\n"; return *this;}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Presidential pardon", 25, 5), target(target) {}

void PresidentialPardonForm::execute(const Bureaucrat& b) const {
	AForm::execute(b);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}
