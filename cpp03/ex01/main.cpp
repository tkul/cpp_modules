#include "ScavTrap.hpp"

int main()
{
    std::cout << "\n=== Testing Construction/Destruction Order ===" << std::endl;
    {
        ScavTrap scav("Guardian");
    }
    
    std::cout << "\n=== Testing ScavTrap Functionality ===" << std::endl;
    ScavTrap scav("Serena");
    
    scav.attack("Enemy");
    scav.takeDamage(30);
    scav.beRepaired(10);
    
    scav.guardGate();
    
    std::cout << "\n=== Testing Energy Points ===" << std::endl;
    for (int i = 0; i < 52; i++) {
        std::cout << "Attack " << i + 1 << ": ";
        scav.attack("Target");
    }
    
    std::cout << "\n=== Testing Destruction ===" << std::endl;
    scav.takeDamage(200);
    scav.attack("Enemy");
    scav.beRepaired(10);
    
    return 0;
}