#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain* brain;
	int	idea_nb;
public:
	Dog();
	Dog(const Dog& a);
	Dog& operator=(const Dog&a);
	virtual ~Dog();
	void makeSound() const;
	void thinkOutLoud() const;
	void brainWash(const std::string& newIdea);
};
