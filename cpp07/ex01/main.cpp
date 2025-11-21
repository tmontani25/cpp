#include "iter.hpp"
#include <iostream>


// Une seule fonction template pour tout tester
template<typename T>
void display(const T& x) {
    std::cout << x << " ";
}

// main.cpp
int main() {
    int numbers[] = {1, 2, 3};
    std::string words[] = {"hello", "world"};
    
    iter(numbers, 3, display<int>);        // Fonctionne
    iter(words, 2, display<std::string>);  // Fonctionne
    
    return 0;
}