// filepath: /Users/teo18/Desktop/cpp01/ex01/main.cpp
#include "Zombie.hpp"

int main() {
    int N = 5;
    Zombie* horde = zombieHorde(N, "Zombie");
    
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }
    
    delete[] horde;  // Important: utiliser delete[] pour un tableau
    
    return 0;
}