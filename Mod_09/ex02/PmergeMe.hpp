#pragma once
#include <vector>
#include <deque>

class PmergeMe {
private:
	std::vector<int> nums;
	static int count;
	struct isLess {
		template<typename T>
		bool operator()(const T& x, const T& y) {count++; return x < y;}
		template<typename T>
		bool operator()(const std::vector<T>& x, const std::vector<T>& y) {; return isLess()(x[0], y[0]);}
		template<typename T>
		bool operator()(const std::deque<T>& x, const std::deque<T>& y) {; return isLess()(x[0], y[0]);}
	};
	int getCount() const;
	void resetCount();

	int jacob(int n);
	void recurse(std::vector<std::vector<int>>& v, int stride=1);
	void recurse(std::deque<std::deque<int>>& d, int stride=1);
	void binInsert(
		std::vector<std::vector<int>>& out,
		std::vector<int>& aIndex,
		std::vector<int>& toInsert,
		int hi);
	void binInsert(
		std::deque<std::deque<int>>& out,
		std::deque<int>& aIndex,
		std::deque<int>& toInsert,
		int hi);

	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
public:
	PmergeMe(std::vector<int>& nums);
	~PmergeMe();

	void vecSort();
	void deqSort();
	void stdSort();
};

