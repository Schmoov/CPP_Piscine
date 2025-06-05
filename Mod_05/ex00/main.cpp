#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat Hermes("Hermes", 2);
		std::cout << Hermes;
		Hermes.decr();
		std::cout << Hermes;
		Hermes.incr();
		std::cout << Hermes;
		Hermes.incr();
		std::cout << Hermes;
		Hermes.incr();
		std::cout << Hermes;
	} catch (std::exception & e) {
		std::cout << "Oops \n";
	}
	/*
	try {
		Bureaucrat Hermes("Hermes", 151);
	} catch (std::exception & e) {
		std::cout << "Oops \n";
	}
	*/
}
