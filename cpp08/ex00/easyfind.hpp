#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <string>
#include <iostream>
#include <algorithm> // pour std::find
#include <stdexcept>
#include <vector>
#include <list>
#include <deque>


template <typename T>
typename T::iterator easyfind(T &container, int value){
    //trouver l'occurence de value dans container
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::out_of_range("Valeur non trouvée");
    return it;
}


#endif

