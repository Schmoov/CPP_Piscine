#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	nb = 0;
	curr = 0;
}

void	PhoneBook::add()
{
	if (nb < 8)
		nb++;
	std::cout << "Enter first name :" << std::endl;
	std::cin >> c[curr].info[0];
	std::cout << "Enter last name :" << std::endl;
	std::cin >> c[curr].info[1];
	std::cout << "Enter nickname :" << std::endl;
	std::cin >> c[curr].info[2];
	std::cout << "Enter phone number :" << std::endl;
	std::cin >> c[curr].info[3];
	std::cout << "Enter secret :" << std::endl;
	std::cin >> c[curr].info[4];
	curr = (curr + 1) % 8;
}

void	PhoneBook::printf()
{
	for (int i = 0; i < nb; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << std::setw(10) << std::right
				<< format(c[i].info[j]) << (j == 4 ? "|" : "");
		}
		std::cout << std::endl;
	}
}

void	PhoneBook::search()
{
	int	idx = 69;
	printf();
	std::cout << "Choose entry :" << std::endl;
	std::cin >> idx;
	if (idx < 1 || idx > 8)
		std::cout << "Pathetic" << std::endl;
	else
		c[idx - 1].print();
}	

std::string	PhoneBook::format(std::string s)
{
	if (s.size() > 10)
		return (s.substr(0, 9) + '.');
	else
		return s;
}
