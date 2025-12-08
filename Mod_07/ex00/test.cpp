#include <iostream>
#include <string>

template<typename T>
void swap(T& v1, T& v2) {
	T tmp = v1; v1 = v2; v2 = tmp;
	std::cerr << "User defined swap\n";
}

int main() {
	int i1 = 42;
	int i2 = 69;
	swap(i1, i2); 
	std::string s1 = "Hello";
	std::string s2 = "world";
	::swap(s1, s2);
}
