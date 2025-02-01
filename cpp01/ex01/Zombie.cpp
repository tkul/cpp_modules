#include "Zombie.hpp"

Zombie::Zombie() {
    name = "Zombie";
}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() {
    std::cout << name << " is dead" << std::endl;
}

void Zombie::announce() const {
    std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}