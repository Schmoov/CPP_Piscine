#include "PhoneBook.hpp"

void	PhoneBook::getStr(std::string prompt, std::string& val)
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
	getStr("Enter a command : ", command);
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
	std::string content;
	getStr("Enter first name : ", content);
	c[curr].setInfo(content, 0);
	getStr("Enter last name : ", content);
	c[curr].setInfo(content, 1);
	getStr("Enter nickname : ", content);
	c[curr].setInfo(content, 2);
	getStr("Enter phone number : ", content);
	c[curr].setInfo(content, 3);
	getStr("Enter secret : ", content);
	c[curr].setInfo(content, 4);
	curr = (curr + 1) % 8;
	nb = std::min(8, nb + 1);
}

void	PhoneBook::search()
{
	if (!nb) {
		std::cout << "Phonebook is empty\n";
		return ;
	}
	for (int i = 0; i < nb; i++) {
		std::cout << std::setw(10) << std::right << i + 1 << '|';
		c[i].printFormat();
	}
	int	idx = 0;
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
	c[idx - 1].printFull();
}	
