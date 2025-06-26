#include "Zombie.hpp"

int main() {
    // Création d'un zombie sur la heap
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    
    // Création d'un zombie sur la stack
    randomChump("Stack Zombie");

    delete heapZombie;
    
    return 0;
}