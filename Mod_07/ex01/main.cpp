#include "iter.hpp"
#include <iostream>
#include <string>

void printStr(const std::string& s) {
	std::cout << s << std::endl;
}

void revStr(std::string& s) {
	for (int i = 0; i < (int)s.size()/2; i++)
		std::swap(s[i], s[s.size() - 1 - i]);
}

void printRevStr(const std::string& s) {
	std::string rev(s.rbegin(), s.rend());
	printStr(rev);
}

int main() {
	const std::string arr1[] = {"One", "Two", "Three"};
	std::string arr2[] = {"Un", "Dos", "Tres"};

	iter(arr1, 3, printStr);
	std::cout << "~~~~~\n";
	//iter(arr1, 3, revStr);
	iter(arr1, 3, printRevStr);
	std::cout << "~~~~~\n";

	iter(arr2, 3, printStr);
	std::cout << "~~~~~\n";
	iter(arr2, 3, printRevStr);
	std::cout << "~~~~~\n";
	iter(arr2, 3, revStr);
	iter(arr2, 3, printStr);
}
