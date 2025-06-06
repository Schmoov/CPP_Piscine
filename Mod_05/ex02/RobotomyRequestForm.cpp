#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{std::cerr << "Skill Issue\n";};
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& o)
	: AForm(o), target(o.target) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& o)
{(void) o; std::cerr << "Skill Issue\n"; return *this;}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy Request", 72, 45), target(target) {}

void RobotomyRequestForm::realExec() const {
	static int rand;
	std::cout << "*Drilling noises*\n";
	if (rand++ % 2)
		std::cout << target << "'s robotomy suceeded\n";
	else
		std::cout << target << "'s robotomy failed\n";
}
