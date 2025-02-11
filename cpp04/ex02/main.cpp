#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    AAnimal* animals[4];

    for (int k = 0; k < 4; ++k) {
        if (k % 2 == 0) {
            animals[k] = new Dog();
        } else {
            animals[k] = new Cat();
        }
    }

    for (int k = 0; k < 4; ++k) {
        animals[k]->makeSound();
    }

    for (int k = 0; k < 4; ++k) {
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