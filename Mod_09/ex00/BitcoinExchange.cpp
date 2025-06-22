#include "BitcoinExchange.hpp"
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>


BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& o) {(void) o;}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o) {(void) o; return *this;}
BitcoinExchange::~BitcoinExchange() {}

void initDb(std::map<int, int>& db) {
	std::ifstream dbCsv("data.csv");
	std::string tmp;
	getline(dbCsv, tmp);
	while (!dbCsv.eof()) {
		std::getline(dbCsv, tmp);
		std::stringstream ss(tmp);
		int key = 0;
		std::string num;
		std::getline(ss, num, '-');
		key += std::stoi(num);
		key *= 13;
		std::getline(ss, num, '-');
		key += std::stoi(num);
		key *= 32;
		std::getline(ss, num, ',');
		key += std::stoi(num);
		std::getline(ss, num);
		db[key] = stoi(num);
	}
}

void BitcoinExchange::solve(std::string& query) {
	std::map<int, int> db;
	initDb(db);

	std::ifstream qCsv(query);
	std::string tmp;
	getline(qCsv, tmp);
	while (!qCsv.eof()) {
		std::getline(qCsv, tmp);
		std::stringstream ss(tmp);
		int key = 0;
		std::string num;
		std::getline(ss, num, '-');
		key += std::stoi(num);
		key *= 13;
		std::getline(ss, num, '-');
		key += std::stoi(num);
		key *= 32;
		std::getline(ss, num, '|');
		key += std::stoi(num);
		std::getline(ss, num);
		int mult = stoi(num);
		
		int val = prev(db.upper_bound(key))->second;
		if (mult <= 0)
			std::cerr << "Error: not a positive number.\n";
		else

	}



