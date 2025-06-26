#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    {
        Weapon club("gun");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("ak-47"); // je peux modifier le l'arme ici
        bob.attack();
    }
    {
        Weapon club("bazooka");
        HumanB jim("Jim");
        jim.setWeapon(club); // je lui donne l'arme
        jim.attack();
        club.setType("uzi"); //pareil modif ici
        jim.attack();
    }
    return 0;
}
