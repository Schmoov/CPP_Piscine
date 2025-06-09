#include <climits>
#include <float.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include "ScalarConverter.hpp"

void iConv(int n) {
	std::cout << "char: ";
	if (n < 0 || n > CHAR_MAX)
		std::cout << "Impossible";
	else if (! std::isprint(static_cast<unsigned char>(n)))
		std::cout << "Non displayable";
	else
		std::cout << static_cast<unsigned char>(n);
	std::cout << '\n';

	std::cout << "int: " << n << "\n";
	std::cout << "float: " << static_cast<float>(n) << "f\n";
	std::cout << "double: " << static_cast<double>(n) << "\n";
}

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
	if (f < static_cast<double>(INT_MIN) || f > static_cast<double>(INT_MAX))
		std::cout << "Out of range";
	else
		std::cout << static_cast<int>(f);
	std::cout << '\n';

	std::cout << "float: " << f << "f\n";
	std::cout << "double: " << f << "\n";
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
	if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		std::cout << "Out of range";
	else
		std::cout << static_cast<int>(d);
	std::cout << '\n';

	std::cout << "float: ";
	if (d < -FLT_MAX || d > FLT_MAX)
		std::cout << "Out of range";
	else
		std::cout << d << "f";
	std::cout << "\n";

	std::cout << "double: " << d << "\n";
}

void fInf(const std::string& s) {
	std::cout << "char: impossible\nint: impossible\nfloat: " << s
			<< "\ndouble: " << s.substr(0, s.size()-1) << "\n";
}

void dInf(const std::string& s) {
	std::cout << "char: impossible\nint: impossible\nfloat: " << s << "f\ndouble: " << s << "\n";
}

void ScalarConverter::convert(const std::string& s) {
	char* end;
	if (s == "+inf" || s == "-inf" || s == "nan")
		dInf(s);
	else if (s == "+inff" || s == "-inff" || s == "nanf")
		fInf(s);
	else if (s[s.size()-1] == 'f') {
		fConv(std::strtof(s.c_str(), &end));
	} else if (s.find('.') != std::string::npos) {
		dConv(std::strtod(s.c_str(), &end));
	} else {
		long long n = std::strtoll(s.c_str(), &end, 10);
		std::cout << n << "\n";
		if (*end || n < INT_MIN || n > INT_MAX)
			dConv(std::strtod(s.c_str(), &end));
		else
			iConv(n);
	}
}
