// filepath: /Users/teo18/Desktop/cpp01/ex00/Zombie.cpp
#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name(name) {
}

Zombie::~Zombie(void) {
    std::cout << this->name << " is destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}