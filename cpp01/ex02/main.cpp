#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;


    std::cout << "Adresse de brain      : " << &brain << std::endl;
    std::cout << "Adresse par stringPTR : " << stringPTR << std::endl;
    std::cout << "Adresse par stringREF : " << &stringREF << std::endl;

    std::cout << "Valeur de brain       : " << brain << std::endl;
    std::cout << "Valeur par stringPTR  : " << *stringPTR << std::endl;
    std::cout << "Valeur par stringREF  : " << stringREF << std::endl;

    return 0;
}

