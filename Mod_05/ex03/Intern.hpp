#pragma once
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern : public AForm {
private:
	typedef AForm* (Intern::*funcPtr)(std::string target);
public:
	Intern();
	~Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);

	AForm* makeS(std::string target);
	AForm* makeP(std::string target);
	AForm* makeR(std::string target);
	AForm* makeForm(std::string name, std::string target);
};
