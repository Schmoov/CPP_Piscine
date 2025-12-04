#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
	PmergeMe sorter;

	std::vector<int> nums = sorter.parse(argc, argv);
	std::vector<std::vector<int>> v;
	for (int i = 0; i < (int)nums.size(); i++) {
		v.push_back({nums[i]});
	}

	sorter.vecSort(v);
	std::cout << "After:\t";
	for (int i = 0; i < (int)v.size(); i++)
		std::cout << v[i][0] << " ";
	std::cout << "\nIt took " << sorter.getCount() << " comparisons !\n";
}
