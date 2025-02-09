#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    
    delete j;
    delete i;
        
    return 0;
}