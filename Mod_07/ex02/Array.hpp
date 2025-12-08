#pragma once

template<typename T>
class Array {
	T* ptr;
	unsigned int len;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& o);
	const Array& operator=(const Array& o);
	T& operator[](unsigned int i);
	const T& operator[](unsigned int i) const;
	~Array();
	unsigned int size() const;
};

#include "Array.tpp"
