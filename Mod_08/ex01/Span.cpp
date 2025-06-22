#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span() : cap(0) {}
Span::Span(unsigned int N) : cap(N) {}
Span::Span(const Span& o) : cap(o.cap), arr(o.arr) {}
Span& Span::operator=(const Span& o) {
	cap = o.getCap();
	arr = o.getArr();
	return *this;
}
Span::~Span() {}

void Span::addNumber(int val) {
	if (arr.size() == cap)
		throw std::logic_error("Span busted");
	arr.push_back(val);
}

int Span::shortestSpan() {
	if (arr.size() < 2)
		throw std::logic_error("Span needs at least 2 elements");
	std::sort(arr.begin(), arr.end());
	int res = arr[1] - arr[0];
	for (unsigned int i = 2; i < arr.size(); i++) {
		res = std::min(res, arr[i] - arr[i-1]);
	}
	return res;
}
	
int Span::longestSpan() {
	if (arr.size() < 2)
		throw std::logic_error("Span needs at least 2 elements");
	std::sort(arr.begin(), arr.end());
	return arr[arr.size()-1] - arr[0];
}

unsigned int Span::getCap() const {return cap;}
const std::vector<int>& Span::getArr() const {return arr;}
