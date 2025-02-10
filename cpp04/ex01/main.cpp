#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "---------------------" << std::endl;

    int k = -1;
    Animal* animals[4];
    while (++k < 4) {
        if (k % 2 == 0)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }
    k = -1;
    while (++k < 4){
        animals[k]->makeSound();
    }
    k = -1;
    while (++k < 4){
        delete animals[k];
    }

    std::cout << "---------------------" << std::endl;

    Cat original;
    original.setIdea(0, "I am the original");

    Cat copy(original);
    std::cout << copy.getIdea(0) << std::endl;
    copy.setIdea(0, "I am the copy");

    std::cout << original.getIdea(0) << std::endl;
    std::cout << copy.getIdea(0) << std::endl;
        
    return 0;
}