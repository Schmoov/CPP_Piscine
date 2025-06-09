#include <climits>
#include <float.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include "ScalarConverter.hpp"

void fConv(float f) {
	std::cout << "char: ";
	if (f < 0 || f > CHAR_MAX)
		std::cout << "Impossible";
	else if (! std::isprint(static_cast<unsigned char>(f)))
		std::cout << "Non displayable";
	else
		std::cout << static_cast<unsigned char>(f);
	std::cout << '\n';

	std::cout << "int: ";
	if (f < INT_MIN || f > INT_MAX)
		std::cout << "Out of range";
	else
		std::cout << static_cast<int>(f);
	std::cout << '\n';

	std::cout << "float: "
			<< std::setprecision(1) << f << "f\n";

	std::cout << "double: "
			<< std::setprecision(1) << f << "\n";
}

void dConv(double d) {
	std::cout << "char: ";
	if (d < 0 || d > CHAR_MAX)
		std::cout << "Impossible";
	else if (! std::isprint(static_cast<unsigned char>(d)))
		std::cout << "Non displayable";
	else
		std::cout << static_cast<unsigned char>(d);
	std::cout << '\n';

	std::cout << "int: ";
	if (d < INT_MIN || d > INT_MAX)
		std::cout << "Out of range";
	else
		std::cout << static_cast<int>(d);
	std::cout << '\n';

	std::cout << "float: ";
	if (d < FLT_MIN || d > FLT_MAX)
		std::cout << "Out of range";
	else
		std::cout << std::setprecision(1) << d << "f\n";

	std::cout << "double: "
			<< std::setprecision(1) << d << "\n";
}

void ScalarConverter::convert(const std::string& s) {
	char* end;
	if (s[s.size()-1] == 'f') {
		fConv(std::strtof(s.c_str(), &end));
	} else if (s.find('.') == s.size()) {
		dConv(std::strtof(s.c_str(), &end));
	} else
		iConv(std::strtol(s.c_str(), &end, 10));
}


