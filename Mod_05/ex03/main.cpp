#include <exception>
#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	Bureaucrat b1("Chief", 3);
	Bureaucrat b2("Lead", 20);
	Bureaucrat b3("Senior", 42);
	Bureaucrat b4("Junior", 100);

	Intern jim;
	AForm* f1 = jim.makeForm("shrubbery creation", "earth");
	AForm* f2 = jim.makeForm("presidential pardon", "Elan musquer");
	AForm* f3 = jim.makeForm("robotomy request", "Bender");
	AForm* f4 = jim.makeForm("rotomy request", "Bender");

	b1.executeForm(*f1);

	b4.signForm(*f1);
	b4.signForm(*f2);
	b4.signForm(*f3);
	b3.signForm(*f1);
	b3.signForm(*f2);
	b3.signForm(*f3);
	b2.signForm(*f1);
	b2.signForm(*f2);
	b2.signForm(*f3);
	b1.signForm(*f1);
	b1.signForm(*f2);
	b1.signForm(*f3);

	b4.executeForm(*f1);
	b4.executeForm(*f2);
	b4.executeForm(*f3);
	b3.executeForm(*f1);
	b3.executeForm(*f2);
	b3.executeForm(*f3);
	b2.executeForm(*f1);
	b2.executeForm(*f2);
	b2.executeForm(*f3);
	b1.executeForm(*f1);
	b1.executeForm(*f2);
	b1.executeForm(*f3);

	delete f1;
	delete f2;
	delete f3;
	delete f4;
}
