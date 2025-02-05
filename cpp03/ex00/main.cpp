#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot("Robot");
    
    std::cout << "\n--- Basic Tests ---" << std::endl;
    robot.attack("Enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    
    std::cout << "\n--- Damage Test ---" << std::endl;
    robot.takeDamage(8);
    robot.attack("Enemy");

    std::cout << "\n--- Energy Test ---" << std::endl;
    ClapTrap robot2("Robot2");
    for (int i = 0; i < 11; i++) {
        robot2.attack("Target");
    }
    
    return 0;
}