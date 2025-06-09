#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "convert expects a single argument";
		return 1;
	}
	ScalarConverter::convert(argv[1]);
}
