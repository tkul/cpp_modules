#include "Zombie.hpp"

int main() {
    randomChump("randomChump");

    Zombie* zombie = newZombie("newZombie");
    zombie->announce();
    delete zombie;

    return 0;
}