#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "PmergeMe.hpp"

int PmergeMe::count = 0;
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) {(void) other;}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void) other;
	return *this;
}
PmergeMe::~PmergeMe(){}

int PmergeMe::getCount() const {
	return PmergeMe::count;
}

void PmergeMe::resetCount() {
	count = 0;
}

std::vector<int> PmergeMe::parse(int argc, char **argv) {
	std::vector<int> input;
	for (int i = 1; i < argc; i++)
		input.push_back(std::stoi(argv[i]));
	std::cout << "Before:\t";
	for (int i = 0; i < (int)input.size(); i++)
		std::cout << input[i] << " ";
	std::cout << std::endl;
	
	return input;
}

int PmergeMe::jacob(int n) {
	return roundl((1LL<<n)/3.) - 1;
}

void PmergeMe::vecSort(std::vector<std::vector<int>>& in, int stride) {
	
	std::vector<std::vector<int>> rec;
	for (int i = 0; i < (int)in.size()/2; i++) {
		if (isLess()(in[i], in[i + in.size()/2])) {
			rec.emplace_back(in[i + in.size()/2]);
			rec[i].insert(rec[i].end(), in[i].begin(), in[i].end());
		} else {
			rec.emplace_back(in[i]);
			rec[i].insert(rec[i].end(), in[i + in.size()/2].begin(), in[i + in.size()/2].end());
		}
	}
	if ((int)rec.size() > 1)
		vecSort(rec, 2*stride);
	std::cout << "rec : \n";
	for (int i = 0; i < (int)rec.size(); i++) {
		for (int j = 0; j < (int)rec[i].size(); j++) {
			std::cout << rec[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';


	std::vector<int> aIndex(rec.size());
	std::vector<std::vector<int>> out(rec.size() + 1);
	out[0].insert(out[0].end(), rec[0].begin() + stride, rec[0].end());

	for (int i = 1; i < (int)rec.size() + 1; i++) {
		out[i].insert(out[i].end(), rec[i-1].begin(), rec[i-1].begin() + stride);
		aIndex[i-1] = i;
	}

	std::cout << "j: ";
	for (int i = 2; jacob(i) < (int)(rec.size() + (in.size()%2)); i++) {
		for (int j = jacob(i+1); j > jacob(i); j--) {
			if ((j == (int)rec.size() && in.size()%2 == 0) || j > (int)rec.size())
				continue;
			std::cout << j << " ";
			std::vector<int> toInsert;
			int hi;
			if (j == (int)rec.size() && (int)in.size()) {
				toInsert = in.back();
				hi = out.size();
			}
			else {
				toInsert = {rec[j].begin() + stride, rec[j].end()};
				hi = aIndex[j];
			}
			binInsert(out, aIndex, toInsert, hi);
		}
	}
	std::cout << "\n";
	std::cout << "out : \n";
	for (int i = 0; i < (int)out.size(); i++) {
		for (int j = 0; j < (int)out[i].size(); j++) {
			std::cout << out[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	in = out;
}
			
void PmergeMe::binInsert(
		std::vector<std::vector<int>>& out,
		std::vector<int>& aIndex,
		std::vector<int>& toInsert,
		int hi) {
	std::vector<std::vector<int>>::iterator it =
		std::upper_bound(out.begin(), out.begin() + hi, toInsert, isLess());
	out.insert(it, toInsert);
	for (int i = 0; i < (int)aIndex.size(); i++) {
		if (aIndex[i] >= it - out.begin())
			aIndex[i]++;
	}
}
