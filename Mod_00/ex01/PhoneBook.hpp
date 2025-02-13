#pragma once

#include "Contact.hpp"

class PhoneBook {
	public :
		Contact	c[8];
		int		nb;
		int		curr;

		PhoneBook();
		void	add();
		void	printf();
		void	search();
		std::string	format(std::string s);
};
