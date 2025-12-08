#pragma once
#include <map>
#include <string>

class BitcoinExchange {
private:
	std::map<std::string, double> db;

	BitcoinExchange(const BitcoinExchange& o);
	BitcoinExchange& operator=(const BitcoinExchange& o);

	bool isValidDate(const std::string& date);
public:
	BitcoinExchange();
	~BitcoinExchange();

	void solve(const char* path);
};

std::map<std::string, double> initDb();
