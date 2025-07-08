#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("DefaultFrag") {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructed (default)" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap " << _name << " copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    ClapTrap::operator=(other);
    std::cout << "FragTrap " << _name << " assigned" << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destroyed" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    std::cout << "FragTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " requests a high five! ✋" << std::endl;
}