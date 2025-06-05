#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : sGrade(69), eGrade(69)
{std::cerr << "Skill Issue\n";}
Form::~Form() {}
Form::Form(const Form& other): name(other.name),  sign(other.sign), sGrade(other.sGrade), eGrade(other.eGrade) {}
Form& Form::operator=(const Form& other)
{(void) other; std::cerr << "Skill Issue\n"; return *this;}

const std::string& Form::getName() const {return name;}
bool Form::isSigned() const {return sign;}
int Form::getSGrade() const {return sGrade;}
int Form::getEGrade() const {return eGrade;}
Form::Form(std::string name, int sGrade, int eGrade)
	: name(name),  sign(false), sGrade(sGrade), eGrade(eGrade) {
	if (eGrade < 1 || sGrade < 1)
		throw Form::GradeTooHighException();
	if (eGrade > 150 || sGrade > 150)
		throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, Form& f) {
	os << f.getName() << ", "
		<< (f.isSigned() ? "signed" : "unsigned")
		<< " form requires " << f.getSGrade()
		<< " to sign and " << f.getEGrade()
		<< " to execute\n";
	return os;
}

void Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() > sGrade)
		throw Form::GradeTooLowException();
	sign = true;
}

