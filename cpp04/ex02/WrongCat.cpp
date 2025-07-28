#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copied" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    WrongAnimal::operator=(other);
    std::cout << "WrongCat assigned" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Miaouuuuuuuuu (wrong)" << std::endl;
}