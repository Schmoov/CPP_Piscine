#pragma once
#include "Contact.hpp"

class PhoneBook {
	public :
		PhoneBook();
		void	command();
		void	add();
		void	printf();
		void	search();

	private :
		Contact	c[8];
		int		nb;
		int		curr;
		void	get_str(std::string prompt, std::string& val);
};
