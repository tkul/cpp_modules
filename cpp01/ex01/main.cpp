#include "Zombie.hpp"

int main() {
    int numberofZombies = 4;
    std::string Zombiename = "Zombie";

    Zombie* horde = zombieHorde(numberofZombies, Zombiename);
    
    for (int i = 0; i < numberofZombies; i++) {
        horde[i].announce();
    }

    delete[] horde;
    std::cout << "Zombies have been deleted." << std::endl;
    return 0;
}