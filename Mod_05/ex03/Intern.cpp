#include <iostream>
#include <fstream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern& o) {}
Intern& Intern::operator=(const Intern& o) {(void) o; return *this;}

AForm* Intern::makeS(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeP(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeR(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target) {
	AForm* res;
	funcPtr arr[3] = {&Intern::makeS, &Intern::makeP, &Intern::makeR};
	std::string names[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	for (int i = 0; i < 3; i++) {
		if (name == names[i]) {
			std::cout << "Intern creates " << name << '\n';
			return (this->*arr[i])(target);
		}
	}
	std::cout << "Intern does know about any " << name << " form\n";
	return nullptr;
}
