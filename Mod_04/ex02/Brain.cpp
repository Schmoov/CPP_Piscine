#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cerr << "Built default brain\n";
}

Brain::Brain(const Brain& b)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = b.ideas[i];
	std::cerr << "Built brain copy\n";
}

Brain& Brain::operator=(const Brain& b)
{
	for (int i = 0; i < 100 && this != &b; i++)
		ideas[i] = b.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cerr << "🤯\n";
}
