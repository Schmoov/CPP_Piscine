template <typename T>
typename T::iterator easyfind(T &cont, int val) {
	return find(cont.begin(), cont.end(), val);
}
