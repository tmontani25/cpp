#include <string>
#include <iostream>
template <typename T> // va fonctionner avec n'importe quel type qui respecte les contraintes de la fonction
void swap(T& a, T& b){ 

    T temp = a;  // Plus concis
    a = b;       // Modifie la variable originale
    b = temp;    // Modifie la variable originale
}

template <typename T>
T &min(T &a, T &b){
    if (a == b)
        return b;
    if (a < b)
        return a;
    else
        return b;
}

template <typename T>
T &max(T &a, T &b){
    if (a == b)
        return b;
    if (a < b)
        return b;
    else
        return a;
}