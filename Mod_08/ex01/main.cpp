#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <list>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout <<  "~~~~~~~~~~~~~~~~~~~\n";
	Span big(100000);
	std::list<int> lst;
	for (int i = 0; i < 50000; i++)
		lst.push_back(5*(std::rand()/10));
	big.addRange(lst.begin(), lst.end());
	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;
}
