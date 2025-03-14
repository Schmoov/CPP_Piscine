#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Contact {
public :
	void	setInfo(std::string& content, int key);
	void	printFormat();
	void	printFull();
private :
	std::string	info[5];
	std::string	format(std::string& s);
};
