#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : sGrade(69), eGrade(69)
{std::cerr << "Skill Issue\n";}
AForm::~AForm() {}
AForm::AForm(const AForm& other): name(other.name),  sign(other.sign), sGrade(other.sGrade), eGrade(other.eGrade) {}
AForm& AForm::operator=(const AForm& other)
{(void) other; std::cerr << "Skill Issue\n"; return *this;}

const std::string& AForm::getName() const {return name;}
bool AForm::isSigned() const {return sign;}
int AForm::getSGrade() const {return sGrade;}
int AForm::getEGrade() const {return eGrade;}
AForm::AForm(std::string name, int sGrade, int eGrade)
	: name(name),  sign(false), sGrade(sGrade), eGrade(eGrade) {
	if (eGrade < 1 || sGrade < 1)
		throw AForm::GradeTooHighException();
	if (eGrade > 150 || sGrade > 150)
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, AForm& f) {
	os << f.getName() << ", "
		<< (f.isSigned() ? "signed" : "unsigned")
		<< " form requires " << f.getSGrade()
		<< " to sign and " << f.getEGrade()
		<< " to execute\n";
	return os;
}

void AForm::beSigned(Bureaucrat& b) {
	if (b.getGrade() > sGrade)
		throw AForm::GradeTooLowException();
	sign = true;
}

void AForm::execute(const Bureaucrat& b) const {
	if (b.getGrade() > eGrade)
		throw AForm::GradeTooLowException();
	if (!sign)
		throw AForm::UnsignedForm();
	return realExec();
}
