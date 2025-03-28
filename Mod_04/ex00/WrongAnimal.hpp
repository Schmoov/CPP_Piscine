#pragma once
#include <string>

class WrongAnimal {
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& a);
	WrongAnimal& operator=(const WrongAnimal&a);
	~WrongAnimal();
	void makeSound() const;
	const std::string& getType() const;
};
