#include "Contact.hpp"

std::string	Contact::format(std::string& s)
{
	if (s.size() > 10)
		return (s.substr(0, 9) + '.');
	else
		return s;
}

void	Contact::print_format()
{
	for (int i = 0; i < 5; i++) {
		std::cout << std::setw(10) << std::right
			<< format(info[i]) << (i == 4 ? '\n' : '|');
	}
}

void	Contact::print_full()
{
	for (int i = 0; i < 5; i++) {
		std::cout << info[i] << '\n';
	}
}
