#pragma once
#include <exception>
#include <string>

class Form;

class Bureaucrat {
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);

	Bureaucrat(std::string name, int grade);
	void incr();
	void decr();
	const std::string& getName() const;
	int getGrade() const;
	
	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};

	void signForm(Form& f);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& b);
