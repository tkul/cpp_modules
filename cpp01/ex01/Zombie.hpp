#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
private:
    std::string name;

public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce() const;
};

Zombie* zombieHorde(int N, std::string name);

#endif