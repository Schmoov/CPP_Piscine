#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	PmergeMe sorter;

	std::vector<int> nums = sorter.parse(argc, argv);
	std::vector<std::vector<int>> v;
	for (int i = 0; i < (int)nums.size(); i++) {
		v.push_back({nums[i], i});
	}

	sorter.vecSort(v);
	sorter.printRes();
	std::cout << "After:\t";
	for (int i = 0; i < (int)v.size(); i++)
		std::cout << v[i][0] << " ";
	std::cout << "\nIt took " << count << " comparisons !\n";
}
