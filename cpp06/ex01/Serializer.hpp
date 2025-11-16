
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>  // Pour uintptr_t
#include "Data.hpp"
#include <string>
#include <iostream>

// Classe non-instanciable avec méthodes statiques
class Serializer {
private:
    Serializer();                                    // Constructeur par défaut
    Serializer(const Serializer& other);            // Constructeur de copie  
    Serializer& operator=(const Serializer& other); // Opérateur d'assignation
    ~Serializer();                                   // Destructeur

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif