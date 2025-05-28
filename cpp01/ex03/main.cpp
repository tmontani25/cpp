#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    {
        Weapon club("gun");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("ak-47");
        bob.attack();
    }
    {
        Weapon club("bazooka");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("uzi");
        jim.attack();
    }
    return 0;
}
