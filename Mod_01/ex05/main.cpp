#include "Harl.hpp"
#include <iostream>

int main()
{
	Harl h;
	std::cout << "debug does :\n";
	h.complain("debug");
	std::cout << "info does :\n";
	h.complain("info");
	std::cout << "warning does :\n";
	h.complain("warning");
	std::cout << "error does :\n";
	h.complain("error");
	std::cout << "trash does :\n";
	h.complain("trash");
}
