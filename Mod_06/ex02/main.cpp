#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <typeinfo>

Base* generate() {
	if (rand()%3) {
		std::cout << "A vs ";
		return new A();
	} else if (rand()%2) {
		std::cout << "B vs ";
		return new B();
	} else {
		std::cout << "C vs ";
		return new C();
	}
}

void identify(Base* p) {
	Base* d = dynamic_cast<A*>(p);
	if (d) {
		std::cout << "A\n";
		return;
	}
	
	d = dynamic_cast<B*>(p);
	if (d) {
		std::cout << "B\n";
		return;
	}
	std::cout << "C\n";
}

void identify(Base& p) {
	try {
		Base& d = dynamic_cast<A&>(p);
		(void) d;
		std::cout << "A\n";
		return;
	} catch (std::bad_cast& e) {}
	try {
		Base& d = dynamic_cast<B&>(p);
		(void) d;
		std::cout << "B\n";
		return;
	} catch (std::bad_cast& e) {}
	std::cout << "C\n";
}

int main() {
	for (int i = 0; i < 100; i++) {
		Base* ptr = generate();
		identify(*ptr);
		delete ptr;
	}
	for (int i = 0; i < 100; i++) {
		Base* ptr = generate();
		identify(ptr);
		delete ptr;
	}
}

