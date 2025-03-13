#include "PhoneBook.hpp"

void	PhoneBook::get_str(std::string prompt, std::string& val)
{
	std::cout << prompt;
	std::cin >> val;
	if (std::cin.eof())
		throw std::string("EOF");
}

PhoneBook::PhoneBook()
{
	nb = 0;
	curr = 0;
}

void	PhoneBook::command()
{
	std::string	command;
	get_str("Enter a command : ", command);
	if (command == "EXIT")
		throw std::string("EXIT");
	if (command == "ADD")
		add();
	if (command == "SEARCH")
		search();
}

void	PhoneBook::add()
{
	get_str("Enter first name : ",		c[curr].info[0]);
	get_str("Enter last name : ",		c[curr].info[1]);
	get_str("Enter nickname : ",		c[curr].info[2]);
	get_str("Enter phone number : ",	c[curr].info[3]);
	get_str("Enter secret : ",			c[curr].info[4]);
	curr = (curr + 1) % 8;
	nb = std::min(8, nb + 1);
}

void	PhoneBook::search()
{
	std::cout << "First Name|Last Name |Nickname  |Number    |Secret    \n";
	for (int i = 0; i < nb; i++) {
		c[i].print_format();
	}
	int	idx;
	std::cout << "Choose entry : ";
	std::cin >> idx;
	if (idx < 1 || idx > nb)
		std::cout << "Pathetic" << std::endl;
	else
		c[idx - 1].print_full();
}	
