#include <vector>
#include <deque>
#include <ctime>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "PmergeMe.hpp"

int PmergeMe::count = 0;
PmergeMe::PmergeMe(std::vector<int>& nums) : nums(nums) {}
PmergeMe::~PmergeMe(){}

int PmergeMe::getCount() const {
	return PmergeMe::count;
}

void PmergeMe::resetCount() {
	count = 0;
}


int PmergeMe::jacob(int n) {
	return roundl((1LL<<n)/3.) - 1;
}

void PmergeMe::vecSort() {
	std::cerr << "Before\t";
	std::vector<std::vector<int>> in;
	for (int i = 0; i < (int)nums.size(); i++) {
		in.push_back({nums[i]});
		std::cerr << in.back()[0] << " ";
	}
	std::cerr << "\n";

	std::clock_t time = std::clock();
	recurse(in);
	time = std::clock() - time;

	std::cerr << "After\t";
	for (int i = 0; i < (int)nums.size(); i++) {
		std::cerr << in[i][0] << " ";
	}
	std::cerr << "\n";
	std::cout << "Using vector it took " << 1000. * time / CLOCKS_PER_SEC << " ms and "
		<< getCount() << " comparisons !\n";
	resetCount();
}

void PmergeMe::recurse(std::vector<std::vector<int>>& in, int stride) {
	
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
		recurse(rec, 2*stride);


	std::vector<int> aIndex(rec.size());
	std::vector<std::vector<int>> out(rec.size() + 1);
	out[0].insert(out[0].end(), rec[0].begin() + stride, rec[0].end());

	for (int i = 1; i < (int)rec.size() + 1; i++) {
		out[i].insert(out[i].end(), rec[i-1].begin(), rec[i-1].begin() + stride);
		aIndex[i-1] = i;
	}

	for (int i = 2; jacob(i) < (int)(rec.size() + (in.size()%2)); i++) {
		for (int j = jacob(i+1); j > jacob(i); j--) {
			if ((j == (int)rec.size() && in.size()%2 == 0) || j > (int)rec.size())
				continue;
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
	in = out;
}

void PmergeMe::binInsert(
		std::vector<std::vector<int>>& out,
		std::vector<int>& aIndex,
		std::vector<int>& toInsert,
		int hi) {
	std::vector<std::vector<int>>::iterator it =
		std::upper_bound(out.begin(), out.begin() + hi, toInsert, isLess());
	int idx = it - out.begin();
	out.insert(it, toInsert);
	for (int i = 0; i < (int)aIndex.size(); i++) {
		if (aIndex[i] >= idx)
			aIndex[i]++;
	}
}

void PmergeMe::deqSort() {
	std::cerr << "Before\t";
	std::deque<std::deque<int>> in;
	for (int i = 0; i < (int)nums.size(); i++) {
		in.push_back({nums[i]});
		std::cerr << in.back()[0] << " ";
	}
	std::cerr << "\n";

	std::clock_t time = std::clock();
	recurse(in);
	time = std::clock() - time;

	std::cerr << "After\t";
	for (int i = 0; i < (int)nums.size(); i++) {
		std::cerr << in[i][0] << " ";
	}
	std::cerr << "\n";
	std::cout << "Using deque it took " << 1000. * time / CLOCKS_PER_SEC << " ms and "
		<< getCount() << " comparisons !\n";
	resetCount();
}

void PmergeMe::recurse(std::deque<std::deque<int>>& in, int stride) {
	
	std::deque<std::deque<int>> rec;
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
		recurse(rec, 2*stride);


	std::deque<int> aIndex(rec.size());
	std::deque<std::deque<int>> out(rec.size() + 1);
	out[0].insert(out[0].end(), rec[0].begin() + stride, rec[0].end());

	for (int i = 1; i < (int)rec.size() + 1; i++) {
		out[i].insert(out[i].end(), rec[i-1].begin(), rec[i-1].begin() + stride);
		aIndex[i-1] = i;
	}

	for (int i = 2; jacob(i) < (int)(rec.size() + (in.size()%2)); i++) {
		for (int j = jacob(i+1); j > jacob(i); j--) {
			if ((j == (int)rec.size() && in.size()%2 == 0) || j > (int)rec.size())
				continue;
			std::deque<int> toInsert;
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
	in = out;
}
			
void PmergeMe::binInsert(
		std::deque<std::deque<int>>& out,
		std::deque<int>& aIndex,
		std::deque<int>& toInsert,
		int hi) {
	std::deque<std::deque<int>>::iterator it =
		std::upper_bound(out.begin(), out.begin() + hi, toInsert, isLess());
	int idx = it - out.begin();
	out.insert(it, toInsert);
	for (int i = 0; i < (int)aIndex.size(); i++) {
		if (aIndex[i] >= idx)
			aIndex[i]++;
	}
}

void PmergeMe::stdSort() {
	std::cerr << "Before\t";
	std::vector<int> in = nums;
	for (int i = 0; i < (int)nums.size(); i++) {
		std::cerr << in[i] << " ";
	}
	std::cerr << "\n";

	std::clock_t time = std::clock();
	std::sort(in.begin(), in.end(), isLess());
	time = std::clock() - time;

	std::cerr << "After\t";
	for (int i = 0; i < (int)nums.size(); i++) {
		std::cerr << in[i] << " ";
	}
	std::cout << "std::sort does it in " << 1000. * time / CLOCKS_PER_SEC << " ms and "
		<< getCount() << " comparisons !\n";
	resetCount();
}

