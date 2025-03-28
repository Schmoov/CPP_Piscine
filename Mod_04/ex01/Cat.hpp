#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain* brain;
public:
	Cat();
	Cat(const Cat& a);
	Cat& operator=(const Cat&a);
	~Cat();
	void makeSound() const;
};
