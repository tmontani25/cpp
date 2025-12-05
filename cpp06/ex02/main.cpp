#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Base.hpp"

// Génère aléatoirement une instance de A, B ou C et la retourne comme pointeur Base*
Base* generate(void) {
    static bool seedSet = false;
    if (!seedSet) {
        srand(time(NULL));
        seedSet = true;
    }
    
    int random = rand() % 3;
    
    if (random == 0) {
        std::cout << "Generated: A" << std::endl;
        return new A();
    }
    else if (random == 1) {
        std::cout << "Generated: B" << std::endl;
        return new B();
    }
    else {
        std::cout << "Generated: C" << std::endl;
        return new C();
    }
}

// Identifie le type réel via un pointeur
void identify(Base* p) {
    if (p == NULL) {
        std::cout << "NULL pointer" << std::endl;
        return;
    }
    
    if (dynamic_cast<A*>(p)) { // bool true ou false
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
    else {
        std::cout << "Unknown type" << std::endl;
    }
}

// Identifie le type réel via une référence (sans utiliser de pointeur)
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception&) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception&) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception&) {}
    
    std::cout << "Unknown type" << std::endl;
}

int main() {
    std::cout << "=== Exercise 02: Identify real type ===" << std::endl;
    
    std::cout << "\n--- Generating objects ---" << std::endl;
    Base* obj1 = generate();
    Base* obj2 = generate();
    Base* obj3 = generate();
    
    std::cout << "\n--- Identification via pointer ---" << std::endl;
    std::cout << "obj1: ";
    identify(obj1);
    std::cout << "obj2: ";
    identify(obj2);
    std::cout << "obj3: ";
    identify(obj3);
    
    std::cout << "\n--- Identification via reference ---" << std::endl;
    std::cout << "obj1: ";
    identify(*obj1);
    std::cout << "obj2: ";
    identify(*obj2);
    std::cout << "obj3: ";
    identify(*obj3);
    
    std::cout << "\n--- Testing edge cases ---" << std::endl;
    std::cout << "NULL pointer: ";
    identify(static_cast<Base*>(NULL));
    
    std::cout << "\n--- Cleanup ---" << std::endl;
    delete obj1;
    delete obj2;
    delete obj3;
    
    std::cout << "Test completed successfully!" << std::endl;
    
    return 0;
}