#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	Bureaucrat b1("Chief", 3);
	Bureaucrat b2("Lead", 20);
	Bureaucrat b3("Senior", 42);
	Bureaucrat b4("Junior", 100);

	ShrubberyCreationForm f1("earth");
	PresidentialPardonForm f2("Elan musquer");
	RobotomyRequestForm f3("Bender");

	b1.executeForm(f1);

	b4.signForm(f1);
	b4.signForm(f2);
	b4.signForm(f3);
	b3.signForm(f1);
	b3.signForm(f2);
	b3.signForm(f3);
	b2.signForm(f1);
	b2.signForm(f2);
	b2.signForm(f3);
	b1.signForm(f1);
	b1.signForm(f2);
	b1.signForm(f3);

	b4.executeForm(f1);
	b4.executeForm(f2);
	b4.executeForm(f3);
	b3.executeForm(f1);
	b3.executeForm(f2);
	b3.executeForm(f3);
	b2.executeForm(f1);
	b2.executeForm(f2);
	b2.executeForm(f3);
	b1.executeForm(f1);
	b1.executeForm(f2);
	b1.executeForm(f3);
}
