#include "PhoneBook.hpp"

void	main_loop()
{
	PhoneBook	book;
	while (true) {
		book.command();
	}
}

int	main()
{
	try {
		main_loop();
	}
	catch (std::string s) {
		if (s == "EOF")
			std::cout << "\nEOF detected, exiting\n";
		else if (s == "EXIT")
			std::cout << "\nExiting\n";
		else
			std::cout << "\nUnexpected error\n";
	}
}
