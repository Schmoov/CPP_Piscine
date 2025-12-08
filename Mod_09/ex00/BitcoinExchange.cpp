#include "BitcoinExchange.hpp"
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>


BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange() {
	std::ifstream input("data.csv");
	if (!input.is_open()) {
		std::cout << "Error: No database\n";
		throw;
	}
	std::string line;
	std::getline(input, line);
	while (std::getline(input, line)) {
		db[line.substr(0, line.find(','))]
				= std::strtod(line.substr(line.find(',') + 1).c_str(), NULL);
	}
}

void BitcoinExchange::solve(const char* path) {
	std::ifstream input(path);
	if (!input.is_open()) {
		std::cout << "Error: Cannot open file\n";
		return;
	}

	std::string line;
	std::getline(input, line);
	while (std::getline(input, line)) {
		std::string s(line);

		std::string date = s.substr(0, s.find(' '));
		if (!isValidDate(date) || s.find('|') == std::string::npos) {
			std::cout << "Error: bad input => " << s << "\n";
			continue;
		}

		std::stringstream ss(s.substr(s.find('|') + 1));
		double value;
		if (!(ss >> value) || value < 0. || value > 1000.) {
			std::cout << "Error: bad input => " << s << "\n";
			continue;
		}

		std::cout << date << " => " << value << " = "
			<< value * (--db.upper_bound(date))->second << "\n";
	}
}

bool BitcoinExchange::isValidDate(const std::string& s) {
	if (s < db.begin()->first)
		return false;
	int year, month, day;
	char c;
	std::stringstream ss(s);
	if (!(ss >> year >> c >> month >> c >> day))
		return false;
	if (year > 2025 || month > 12 || day > 31)
		return false;
	return true;
}
