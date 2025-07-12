#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== Création d'un ScavTrap ===" << std::endl;
    ScavTrap s1("Serena");
    s1.attack("intruder");
    s1.takeDamage(30);
    s1.beRepaired(20);
    s1.guardGate();

    std::cout << "\n=== Test du constructeur de copie ===" << std::endl;
    ScavTrap s2(s1);
    s2.attack("another intruder");
    s2.guardGate();

    std::cout << "\n=== Test de l'opérateur d'assignation ===" << std::endl;
    ScavTrap s3;
    s3 = s1;
    s3.attack("third intruder");
    s3.guardGate();

    std::cout << "\n=== Fin du programme ===" << std::endl;
    return 0;
}