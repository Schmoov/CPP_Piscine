#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

void peanutTheThird(const Dog& dog)
{
	Dog PeanutIII;
	PeanutIII = dog;
	PeanutIII.brainWash("I has a bad feeling about dis");
	PeanutIII.thinkOutLoud();
}

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	Dog Peanut;

	Peanut.brainWash("Me likes Chimken");
	Peanut.brainWash("Such idea");
	Peanut.thinkOutLoud();

	Dog PeanutII(Peanut);
	PeanutII.brainWash("Very copy");
	PeanutII.thinkOutLoud();
	peanutTheThird(PeanutII);

}
