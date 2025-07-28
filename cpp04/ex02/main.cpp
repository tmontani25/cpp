#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Correct Polymorphism ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    //const Animal* meta = new Animal(); ne fonctionne pas parce que animal est une classe abstraite

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // Meow
    j->makeSound(); // Woof

    delete j;
    delete i;

    std::cout << "\n=== Wrong Polymorphism ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // WrongAnimal sound (pas virtuel)
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;

    return 0;
}