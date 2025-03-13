#include "PhoneBook.hpp"

void	PhoneBook::get_str(std::string prompt, std::string& val)
{
	std::cout << prompt;
	std::getline(std::cin, val);
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
	else if (command == "ADD")
		add();
	else if (command == "SEARCH")
		search();
	else
		std::cout << "Invalid command\n";
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
	if (!nb) {
		std::cout << "Phonebook is empty\n";
		return ;
	}
	std::cout << "First Name|Last Name |Nickname  |Number    |Secret    \n\n";
	for (int i = 0; i < nb; i++) {
		c[i].print_format();
	}
	int	idx;
	std::cout << "Choose entry : ";
	std::cin >> idx;
	while (idx < 1 || idx > nb) {
		std::cin.clear();
		std::cin.ignore(1 << 20, '\n');
		if (std::cin.eof())
			throw std::string("EOF");
		std::cout << "Please enter a valid entry (between 1 and " << nb << ")\n";
		std::cout << "Choose entry : ";
		std::cin >> idx;
	}
	std::cin.clear();
	std::cin.ignore(1 << 20, '\n');
	if (std::cin.eof())
		throw std::string("EOF");
	c[idx - 1].print_full();
}	
