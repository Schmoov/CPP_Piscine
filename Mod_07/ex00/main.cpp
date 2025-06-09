#include <iostream>
#include "whatever.hpp"

int main() {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	/*
	int i1 = 42;
	int i2 = 69;
	swap(i1, i2);
	std::cout << i1 << " " << i2 << "\n";

	std::string s1 = "Hello";
	std::string s2 = "world";
	swap(s1, s2);
	std::cout << s1 << " " << s2 << "\n";
	*/
}
