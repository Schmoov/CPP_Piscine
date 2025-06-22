#pragma once
#include <string>

class RPN {
public:
	RPN();
	RPN(const RPN& o);
	RPN& operator=(const RPN& o);
	~RPN();

	static int solve(std::string& s);
};
