#pragma once
#include <string>

class ScalarConverter {
public:
	static void convert(const std::string& s);
	virtual ~ScalarConverter() = 0;
};
