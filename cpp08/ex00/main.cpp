#include "easyfind.hpp"

int main(void){
    std::cout << "TEST AVEC UN VECTOR\n\n";
    std::vector<int> v;
    std::vector<int>::iterator it;
    v.push_back(10);
    v.push_back(20);
    v.push_back(5);

try {
    it = easyfind(v, 5);
} catch (const std::exception& e){
    std::cout << "Erreur : " << e.what() << std::endl;
}

std::cout << "it address: " << &it << std::endl;
std::cout << "\nvalue found: "<< *it << std::endl;

std::cout << "\n\nTEST AVEC UNE UNE VALEUR QUI N'EST PAS DANS LE CONTAINER v\n";

try {
    it = easyfind(v, 1000);
} catch (const std::exception& e){
    std::cout << "Erreur : " << e.what() << std::endl;
}






std::cout << "\n\n\n\nTEST AVEC UN AUTRE TYPE DE CONTAINER l\n";

    std::list<int> l;
    std::list<int>::iterator itL;
    l.push_back(10);
    l.push_back(20);
    l.push_back(5);

try {
    itL = easyfind(l, 5);
} catch (const std::exception& e){
    std::cout << "Erreur : " << e.what() << std::endl;
}

std::cout << "it address: " << &it << std::endl;
std::cout << "\nvalue found: "<< *it << std::endl;

std::cout << "\n\nTEST AVEC UNE UNE VALEUR QUI N'EST PAS DANS LE CONTAINER l\n";

try {
    itL = easyfind(l, 1000);
} catch (const std::exception& e){
    std::cout << "Erreur : " << e.what() << std::endl;
}

}