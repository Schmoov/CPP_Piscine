#include "iter.hpp"
#include <iostream>
#include <string>

void printStr(const std::string& s) {
	std::cout << s << std::endl;
}

void revStr(std::string& s) {
	for (int i = 0; i < (int)s.size()/2; i++)
		std::swap(s[i], s[s.size() - 1 - i]);
}

void printRevStr(const std::string& s) {
	std::string rev(s.rbegin(), s.rend());
	printStr(rev);
}

int main() {
	const std::string arr1[] = {"One", "Two", "Three"};
	std::string arr2[] = {"Un", "Dos", "Tres"};

	iter(arr1, 3, printStr);
	std::cout << "~~~~~\n";
	//iter(arr1, 3, revStr);
	iter(arr1, 3, printRevStr);
	std::cout << "~~~~~\n";

	iter(arr2, 3, printStr);
	std::cout << "~~~~~\n";
	iter(arr2, 3, printRevStr);
	std::cout << "~~~~~\n";
	iter(arr2, 3, revStr);
	iter(arr2, 3, printStr);
}

/*
class Awesome
{
	public:
		Awesome(void): _n( 42 ) { return; }
		int get(void) const { return this->_n; }
	private:
		int _n;
};
std::ostream & operator<< (std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
template<typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }
int main() {
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
	Awesome tab2[5];
	iter( tab, 5, print);
	iter( tab2, 5, print);
	return 0;
}
*/
