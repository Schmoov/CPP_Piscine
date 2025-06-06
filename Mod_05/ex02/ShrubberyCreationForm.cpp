#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{std::cerr << "Skill Issue\n";};
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& o)
	: AForm(o), target(o.target) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& o)
{(void) o; std::cerr << "Skill Issue\n"; return *this;}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery creation", 145, 137), target(target) {}

void ShrubberyCreationForm::execute(const Bureaucrat& b) const {
	AForm::execute(b);
	const std::string fName = target + "_shrubbery";
	std::ofstream outfile(fName.c_str());
	outfile << "  *\n / \\  *\n/   \\/ \\" << std::endl;
	outfile.close();
}
