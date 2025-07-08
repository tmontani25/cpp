#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Bob");
    ClapTrap b("Alice");

    a.attack("Alice");
    b.takeDamage(0);
    b.beRepaired(2);

    a.takeDamage(5);
    a.beRepaired(3);

    return 0;
}