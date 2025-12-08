#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(4);
	vec.push_back(4);
	vec.push_back(5);

	const std::list<int> lst(vec.begin(), vec.end());
	//std::list<int> lst(vec.begin(), vec.end());

	std::vector<int>::iterator it = easyfind(vec, 2);
	if (it != vec.end())
		std::cout << "Found " << *it << " at pos " << it - vec.begin() << "\n";
	else 
		std::cout << "Cannot find " << 2 << "\n";
	it = easyfind(vec, 6);
	if (it != vec.end())
		std::cout << "Found " << *it << " at pos " << it - vec.begin() << "\n";
	else 
		std::cout << "Cannot find " << 6 << "\n";
	it = easyfind(vec, 4);
	if (it != vec.end())
		std::cout << "Found " << *it << " at pos " << it - vec.begin() << "\n";
	else 
		std::cout << "Cannot find " << 4 << "\n";


	std::list<int>::const_iterator it2 = easyfind(lst, 2);
	if (it2 != lst.end())
		std::cout << "Found " << *it2 << "\n";
	else 
		std::cout << "Cannot find " << 2 << "\n";
	it2 = easyfind(lst, 6);
	if (it2 != lst.end())
		std::cout << "Found " << *it2 << "\n";
	else 
		std::cout << "Cannot find " << 6 << "\n";
	it2 = easyfind(lst, 4);
	if (it2 != lst.end())
		std::cout << "Found " << *it2 << "\n";
	else 
		std::cout << "Cannot find " << 4 << "\n";
}
