#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;


	Character Bobby("leB");
	Ice	m;
	Bobby.equip(m.clone());
	Bobby.equip(m.clone());
	Bobby.equip(m.clone());
	Bobby.equip(m.clone());
	Bobby.equip(m.clone());
	Bobby.equip(m.clone());
	Bobby.equip(m.clone());
	Bobby.equip(m.clone());
	Bobby.unequip(69);
	Bobby.unequip(2);
	Bobby.unequip(2);
	Bobby.equip(m.clone());
	Bobby.unequip(2);


	return 0;
}
