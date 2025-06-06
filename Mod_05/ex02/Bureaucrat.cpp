#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

void Bureaucrat::signForm(AForm& f) {
	if (f.isSigned()) {
		std::cout << getName() << " couldn't sign " << f.getName() << " because it is already signed\n";
		return;
	}
	try {
		f.beSigned(*this);
	}
	catch (AForm::GradeTooLowException& e) {}
	if (f.isSigned())
		std::cout << getName() << " signed " << f.getName() << "\n";
	else
		std::cout << getName() << " couldn't sign " << f.getName() << " because their grade is too low\n";
}

void Bureaucrat::executeForm(const AForm& f) const {
	try {
		f.execute(*this);
		std::cout << getName() << " executed " << f.getName() << '\n';
	} catch (AForm::UnsignedForm& e) {
		std::cout << f.getName() << " cannot be executed until it is signed\n";
	} catch (AForm::GradeTooLowException& e) {
		std::cout << getName() << " has too low rank to execute " << f.getName() << '\n';
	} catch (std::exception& e) {
		std::cout << "an explicit error message\n";
	}
}
