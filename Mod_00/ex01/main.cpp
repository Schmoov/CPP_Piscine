#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int	main()
{
	PhoneBook	book;
	std::string s;
	while (true) {
		std::cout << "Enter a command :" << std::endl;
		std::cin >> s;
		if (s == "ADD")
			book.add();
		else if (s == "SEARCH")
			book.search();
		else if (s == "EXIT")
			return 0;
	}
}
