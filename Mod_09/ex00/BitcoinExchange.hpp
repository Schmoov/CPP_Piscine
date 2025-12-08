#pragma once
#include <map>
#include <string>

class BitcoinExchange {
private:
	std::map<std::string, double> db;
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& o);
	BitcoinExchange& operator=(const BitcoinExchange& o);
public:
	BitcoinExchange(const std::string& path);
	~BitcoinExchange();
};

std::map<std::string, double> initDb();
