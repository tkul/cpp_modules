#include "Zombie.hpp"

int main() {
    int numberofZombies = 4;
    std::string Zombiename = "Zombie";

    Zombie* horde = zombieHorde(numberofZombies, Zombiename);
    
    for (int i = 0; i < numberofZombies; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}