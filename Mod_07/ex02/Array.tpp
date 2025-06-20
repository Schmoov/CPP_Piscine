#include "Array.hpp"
#include <stdexcept>

template<typename T>
Array<T>::Array() : ptr(0), len(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : ptr(new T[n]), len(n) {}

template<typename T>
Array<T>::Array(const Array& o)  : ptr(new T[o.len]), len(o.len) {
	for (unsigned int i = 0; i < len; i++)
		ptr[i] = o.ptr[i];
}

template<typename T>
const Array<T>& Array<T>::operator=(const Array& o) {
	if (this != &o) {
		delete[] ptr;
		len = o.len;
		ptr = new T[len];
		for (unsigned int i = 0; i < len; i++)
			ptr[i] = o.ptr[i];
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= len)
		throw std::out_of_range("Skill Issue");
	return ptr[i];
}

template<typename T>
Array<T>::~Array() {
	delete[] ptr;
}

template<typename T>
unsigned int Array<T>::size() const {
	return len;
}
