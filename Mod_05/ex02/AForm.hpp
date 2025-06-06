#pragma once
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class AForm {
private:
	const std::string name;
	bool sign;
	const int sGrade;
	const int eGrade;
public:
	AForm();
	virtual ~AForm() = 0;
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);

	AForm(std::string name, int sGrade, int eGrade);
	const std::string& getName() const;
	bool isSigned() const;
	int getSGrade() const;
	int getEGrade() const;
	
	void beSigned(Bureaucrat& b);
	void execute(Bureaucrat const & b) const;

	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};
	class UnsignedForm : public std::exception {};
};

std::ostream& operator<<(std::ostream& os, AForm& b);
