#include "Serializer.hpp"
#include <iostream>

int main() {
	Data d1 = {42, 'w', "Coco", 47.34};
	uintptr_t addr = Serializer::serialize(&d1);
	Data *d2 = Serializer::deserialize(addr);

	std::cout << "og: " << &d1 << '\n';
	std::cout << "nu: " << d2 << '\n';
	std::cout << d2->num << '\n';
	std::cout << d2->letter << '\n';
	std::cout << d2->name << '\n';
	std::cout << d2->size << '\n';
}
