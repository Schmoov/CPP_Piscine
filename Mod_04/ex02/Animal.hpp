#pragma once
#include <string>

class Animal {
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& a);
	Animal& operator=(const Animal&a);
	virtual ~Animal();
	virtual void makeSound() const = 0;
	const std::string& getType() const;
};
