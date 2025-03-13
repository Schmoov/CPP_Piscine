#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Contact {
	public :
		std::string	info[5];
		void print_format();
		void print_full();
	private :
		std::string	format(std::string& s);
};
