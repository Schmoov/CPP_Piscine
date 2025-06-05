#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void Bureaucrat::signForm(Form& f) {
	if (f.isSigned()) {
		std::cout << getName() << " couldn't sign " << f.getName() << " because it is already signed\n";
		return;
	}
	try {
		f.beSigned(*this);
	}
	catch (Form::GradeTooLowException) {}
	if (f.isSigned())
		std::cout << getName() << " signed " << f.getName() << "\n";
	else
		std::cout << getName() << " couldn't sign " << f.getName() << " because their grade is too low\n";
}
