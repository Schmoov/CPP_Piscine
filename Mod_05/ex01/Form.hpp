#pragma once
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Form {
private:
	const std::string name;
	bool sign;
	const int sGrade;
	const int eGrade;
public:
	Form();
	~Form();
	Form(const Form& other);
	Form& operator=(const Form& other);

	Form(std::string name, int sGrade, int eGrade);
	const std::string& getName() const;
	bool isSigned() const;
	int getSGrade() const;
	int getEGrade() const;
	
	void beSigned(Bureaucrat& b);

	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};
};

std::ostream& operator<<(std::ostream& os, Form& b);
