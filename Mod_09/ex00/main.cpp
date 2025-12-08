#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Error: btc expects a single argument\n";
		return 69;
	}
	BitcoinExchange btc;
	btc.solve(argv[1]);
}
