#include "Zombie.hpp"

int main() {
    // Création d'un zombie sur le heap (tas)
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    
    // Création d'un zombie sur la stack (pile)
    randomChump("Stack Zombie");
    
    // N'oubliez pas de libérer la mémoire du zombie créé sur le heap
    delete heapZombie;
    
    return 0;
}