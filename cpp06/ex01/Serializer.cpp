#include "Serializer.hpp"

// Convertit un pointeur Data* en entier uintptr_t
//uintptr entier suffisament grand pour stocker un ptr de n'importe quel type
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

// Convertit un entier uintptr_t en pointeur Data*
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}