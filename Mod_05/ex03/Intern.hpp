#pragma once
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Intern : public AForm {
public:
	Intern();
	~Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);

	AForm* makeForm(std::string name, std::string target);
};
