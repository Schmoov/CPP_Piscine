#pragma once
#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat& a);
	Cat& operator=(const Cat&a);
	~Cat();
	void makeSound() const;
};
