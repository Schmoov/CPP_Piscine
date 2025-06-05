#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{std::cerr << "Skill Issue\n";}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{(void) other; std::cerr << "Skill Issue\n"; return *this;}

const std::string& Bureaucrat::getName() const {return name;}
int Bureaucrat::getGrade() const {return grade;}
Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::incr() {
	grade--;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decr() {
	grade++;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& b) {
	os << b.getName() << ", bureacrat grade " << b.getGrade() << '\n';
	return os;
}
