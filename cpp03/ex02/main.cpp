#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "=== Testing ClapTrap ===" << std::endl;
    ClapTrap a("A");
    a.attack("target");
    a.takeDamage(5);
    a.beRepaired(3);
    
    std::cout << "\n=== Testing ScavTrap ===" << std::endl;
    ScavTrap b("B");
    b.attack("target");
    b.guardGate();
    b.takeDamage(30);
    b.beRepaired(10);
    
    std::cout << "\n=== Testing FragTrap ===" << std::endl;
    FragTrap c("C");
    c.attack("target");
    c.highFivesGuys();
    c.takeDamage(50);
    c.beRepaired(20);
    
    return 0;
}