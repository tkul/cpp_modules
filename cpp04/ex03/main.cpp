#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
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

    std::cout << "---------------------" << std::endl;

    IMateriaSource* materia  = new MateriaSource();
    materia->learnMateria(new Ice());
    materia->learnMateria(new Cure());

    ICharacter* character = new Character("character");

    AMateria* materia1 = materia->createMateria("ice");
    character->equip(materia1);
    AMateria* materia2 = materia->createMateria("cure");
    character->equip(materia2);

    ICharacter* enemy = new Character("enemy");

    character->use(0, *enemy);
    character->use(1, *enemy);

    delete enemy;
    delete character;
    delete materia;

    return 0;
}