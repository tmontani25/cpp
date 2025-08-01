#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();



    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // miaou miaou
    j->makeSound(); // Waf! Waf!
    meta->makeSound(); // Generic

    std::cout << "\n\npolymorphisme faux\n\n "<< std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // WrongAnimal sound (pas virtuel)
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;

    delete meta;
    delete j;
    delete i;
    return 0;
}