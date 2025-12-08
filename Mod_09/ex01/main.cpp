#include "RPN.hpp"
#include <exception>
#include <iostream>

int main(int c, char** v) {
	if (c != 2) {
		std::cerr << "RPN expects a single argument\n";
		return 69;
	}
	std::string s(v[1]);
	try {
		std::cout << RPN::solve(s) << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Error\n";
	}
}
