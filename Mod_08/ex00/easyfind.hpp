#pragma once
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& cont, int val) {
	return std::find(cont.begin(), cont.end(), val);
}

template <typename T>
typename T::const_iterator easyfind(const T& cont, int val) {
	return std::find(cont.begin(), cont.end(), val);
}
