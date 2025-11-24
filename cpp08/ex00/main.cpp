#include "easyfind.hpp"

int main(void){

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

    std::cout << "\n\nTEST AVEC UNE UNE VALEUR QUI N'EST PAS DANS LE CONTAINER\n";

try {
    it = easyfind(v, 1000);
} catch (const std::exception& e){
    std::cout << "Erreur : " << e.what() << std::endl;
}



}