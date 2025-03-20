#include "Harl.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "harlFilter expects a single argument\n";
		return EXIT_FAILURE;
	}

	std::string strs[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int lvl = 420;
	for (int i = 0; i < 4; i++) {
		if (strs[i] == argv[1])
			lvl = i;
	}

	Harl h;
	switch (lvl) {
	case 0 :
		std::cout << "[ DEBUG ]\n";
		h.complain("debug");
		std::cout << "\n";
	case 1 :
		std::cout << "[ INFO ]\n";
		h.complain("info");
		std::cout << "\n";
	case 2 :
		std::cout << "[ WARNING ]\n";
		h.complain("warning");
		std::cout << "\n";
	case 3 :
		std::cout << "[ ERROR ]\n";
		h.complain("error");
		std::cout << "\n";
		break;
	default :
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
