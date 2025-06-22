#include "RPN.hpp"
#include <exception>
#include <stack>

RPN::RPN() {}
RPN::RPN(const RPN& o) {(void) o;}
RPN& RPN::operator=(const RPN& o) {(void) o; return *this;}
RPN::~RPN() {}

int RPN::solve(std::string& s) {
	std::stack<int> stk;

	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == ' ')
			continue;
		if (s[i] >= '0' && s[i] <= '9') {
			stk.push(s[i] - '0');
			continue;
		}
		if (stk.size() < 2)
			throw std::exception();
		int v2 = stk.top();
		stk.pop();
		int v1 = stk.top();
		stk.pop();
		switch (s[i]) {
			case '+' :
				stk.push(v1 + v2);
				break;
			case '-' :
				stk.push(v1 - v2);
				break;
			case '*' :
				stk.push(v1 * v2);
				break;
			case '/' :
				if (!v2)
					throw std::exception();
				stk.push(v1 / v2);
				break;
			default :
				throw std::exception();
		}
	}
	if (stk.size() != 1)
		throw std::exception();
	return stk.top();
}
