#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
    std::cout << "ClapTrap " << name << " is created!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (energyPoints == 0) {
        std::cout << "ClapTrap " << name << " has no energy points left!" << std::endl;
        return;
    }
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " has no hit points left!" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target 
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already out of hit points!" << std::endl;
        return;
    }
    if (amount >= hitPoints)
        hitPoints = 0;
    else
        hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " damage! "
              << "Hit points left: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints == 0) {
        std::cout << "ClapTrap " << name << " has no energy points left!" << std::endl;
        return;
    }
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " has no hit points left!" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount 
              << " points. Hit points now: " << hitPoints << std::endl;
}