#pragma once
#include <iterator>
#include <vector>
#include <stdexcept>

class Span {
private:
	unsigned int cap;
	std::vector<int> arr;
public:
	Span();
	Span(unsigned int N);
	Span(const Span& o);
	Span& operator=(const Span& o);
	~Span();

	void addNumber(int val);
	int shortestSpan();
	int longestSpan();
	unsigned int getCap() const;
	const std::vector<int>& getArr() const;

	template<typename IT>
	void addRange(IT first, IT last) {
		size_t len = std::distance(first, last);
		if (arr.size() + len  > cap)
			throw std::logic_error("Span busted");
		arr.insert(arr.end(), first, last);
	}
};
