#pragma once
#include <iostream>

template<typename T>
void swap(T& v1, T& v2) {
	std::cerr << "\nUsing my swap \n";
	T tmp = v1;
	v1 = v2;
	v2 = tmp;
}

template<typename T>
T& min(T& v1, T& v2) {
	std::cerr << "\nUsing my min \n";
	if (v1 < v2)
		return v1;
	return v2;
}

template<typename T>
T& max(T& v1, T& v2) {
	std::cerr << "\nUsing my max \n";
	if (v1 > v2)
		return v1;
	return v2;
}
