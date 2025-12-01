#pragma once
#include <vector>

class PmergeMe {
private:
	int count;
	bool isLess(std::vector<std::vector<int>>& v1, std::vector<std::vector<int>>& v2);
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	int getCount() const;
	void resetCount();
	std::vector<int> parse(int argc, char **argv);
	void vecSort(std::vector<std::vector<int>>& v, int size=1);

};

