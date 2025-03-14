#pragma once
#include "Contact.hpp"

class PhoneBook {
	public :
		PhoneBook();
		void	command();
	private :
		Contact	c[8];
		int		nb;
		int		curr;
		void	getStr(std::string prompt, std::string& val);
		void	add();
		void	search();
};
