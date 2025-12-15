#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << "PmergeMe expects a positive integer sequence\n";
		return 69;
	}
	std::vector<int> nums(argc - 1);
	for (int i = 1; i < argc; i++) {
		char* end;
		long long val = std::strtoll(argv[i], &end, 10);
		if (argv[i][0] == 0 || val > std::numeric_limits<int>::max() || val < 0 || *end) {
			std::cerr << "PmergeMe expects a positive integer sequence\n";
			return 69;
		}
		nums[i-1] = val;
	}

	PmergeMe sorter(nums);

	sorter.vecSort();
	sorter.deqSort();
	sorter.stdSort();
}
