#include "Contact.hpp"

void	Contact::setInfo(std::string& content, int key)
{
	info[key] = content;
}

std::string	Contact::format(std::string& s)
{
	if (s.size() > 10)
		return (s.substr(0, 9) + '.');
	else
		return s;
}

void	Contact::printFormat()
{
	for (int i = 0; i < 3; i++) {
		std::cout << std::setw(10) << std::right
			<< format(info[i]) << (i == 2 ? '\n' : '|');
	}
}

void	Contact::printFull()
{
	for (int i = 0; i < 5; i++) {
		std::cout << info[i] << '\n';
	}
}
