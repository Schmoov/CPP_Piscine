#pragma once
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string target;
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	RobotomyRequestForm(std::string target);
	
	void execute(const Bureaucrat& b) const;
};
