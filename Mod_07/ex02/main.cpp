#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
	Array<std::string> a1(3);
	a1[0] = "One";
	a1[1] = "Two";
	a1[2] = "Three";
	Array<std::string> a2(a1);
	a2 = a1;
	a1[0] = "Uno";
	for (int i = 0; i < (int)a2.size(); i++)
		std::cout << a2[i] << std::endl;
	for (int i = 0; i < (int)a2.size(); i++)
		std::cout << a1[i] << std::endl;
	//a2[-1];
	Array<int> arr;
	Array<int> a(0);
	Array<int> b(arr);


	const Array<int> v(4);
	std::cout << v[2];
	//v[2] = 4;
	v.size();
	const Array<int> v2(v);
	//v = v2;
	/*
	Array<const int> u(4);
	std::cout << u[2];
	//u[2] = 4;
	u.size();
	*/
}
