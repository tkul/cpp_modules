#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Meow Meow" << std::endl;
}

void WrongCat::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        brain->setIdea(index, idea);
}

std::string WrongCat::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return brain->getIdea(index);
    return "";
}