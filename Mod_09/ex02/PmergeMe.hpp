#pragma once
#include <vector>

class PmergeMe {
private:
	static int count;
	struct isLess {
		template<typename T>
		bool operator()(const T& x, const T& y) {count++; return x < y;}
		template<typename T>
		bool operator()(const std::vector<T>& x, const std::vector<T>& y) {; return isLess()(x[0], y[0]);}
	};
public:
	int jacob(int n);
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	int getCount() const;
	void resetCount();
	std::vector<int> parse(int argc, char **argv);
	void binInsert(
		std::vector<std::vector<int>>& out,
		std::vector<int>& aIndex,
		std::vector<int>& toInsert,
		int hi);
	void vecSort(std::vector<std::vector<int>>& v, int stride=1);

};

