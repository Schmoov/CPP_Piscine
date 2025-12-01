#include <vector>
#include <iostream>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): count(0) {}
PmergeMe::PmergeMe(const PmergeMe& other): count(other.count) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	count = other.count;
	return *this;
}
PmergeMe::~PmergeMe(){}

int PmergeMe::getCount() const {
	return count;
}

void PmergeMe::resetCount() {
	count = 0;
}

bool PmergeMe::isLess(std::vector<std::vector<int>>& v1, std::vector<std::vector<int>>& v2) {
	count++;
	return v1[0][0] <= v2[0][0];
}

std::vector<int> PmergeMe::parse(int argc, char **argv) {
	std::vector<int> input;
	std::cout << "Before:\t";
	for (int i = 1; i < argc; i++) {
		input.push_back(std::stoi(argv[i]));
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
	
	return input;
}

void PmergeMe::vecSort(std::vector<std::vector<int>>& v, int size) {
	if (v.size() == 1)
		return;

	for (int i = 0; i < v.size()/2; i++) {
		if (v[2*i][0] >= v[2*i+1][0]) {
			big[i] = {v[2*i][0], i};
			smol[i] = v[2*i+1][0];
		} else {
			big[i] = {v[2*i+1][0], i};
			smol[i] = v[2*i][0];
		}
	}
	if (v.size() % 2 == 0)
		smol.rbegin() = *v.rbegin()[0];

	mergeInsert(big);
	std::vector<int> b;
	for (int i = 0; i < (int)smol.size(); i++) {
		b.push_back(smol[big[i][1]]);
	}
}
