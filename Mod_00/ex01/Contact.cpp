#include "Contact.hpp"
#include <string>
#include <iostream>

void	Contact::print()
{
	for (int i = 0; i < 5; i++) {
		std::cout << info[i] << '\n';
	}
}
