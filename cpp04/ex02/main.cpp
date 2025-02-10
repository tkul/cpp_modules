#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {

    // I will code main function here and it will include more details

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    
    delete j;
    delete i;
        
    return 0;
}