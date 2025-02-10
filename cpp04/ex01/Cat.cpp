#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*(other.brain));
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*(other.brain));
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        brain->setIdea(index, idea);
    }
}

std::string Cat::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return brain->getIdea(index);
    }
    return "";
}