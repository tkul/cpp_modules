#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << name << " is created!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " is destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (energyPoints == 0) {
        std::cout << "ScavTrap " << name << " has no energy points left!" << std::endl;
        return;
    }
    if (hitPoints == 0) {
        std::cout << "ScavTrap " << name << " has no hit points left!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " brutally attacks " << target 
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}