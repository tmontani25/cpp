// filepath: /Users/teo18/Desktop/cpp01/ex01/zombieHorde.cpp
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return NULL;
        
    Zombie* horde = new Zombie[N];
    
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    
    return horde;
}