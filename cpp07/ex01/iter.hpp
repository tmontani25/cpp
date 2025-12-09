#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename F> // fonctionne avec n'importe quel type qui respecte les contraintes de ma fonction
void iter(T* array, size_t len, F func) {
    for (size_t i = 0; i < len; i++) {
        func(array[i]);
    }
}

#endif
