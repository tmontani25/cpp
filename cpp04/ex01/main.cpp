#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* animals[4];

    for (int i = 0; i < 2; ++i)
        animals[i] = new Dog();
    for (int i = 2; i < 4; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < 4; ++i) {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; ++i)
        delete animals[i];

    // Test deep copy
    Dog basic;
    {
        Dog tmp = basic;
    } // tmp détruit ici, pas de fuite mémoire

    return 0;
}