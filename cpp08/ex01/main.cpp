#include "Span.hpp"



int main(void){

std::cout<< "TEST SPAN CAPACITE = 0\n";
try {
    Span testSpan(0);
} catch (const std::exception& e) {
    std::cout << "Erreur lors de la création du Span : " << e.what() << std::endl;
}

std::cout<< "TEST SPAN CAPACITE N = NEGATIF\n";
try {
    Span testSpan(-10);
} catch (const std::exception& e) {
    std::cout << "Erreur lors de la création du Span : " << e.what() << std::endl;
}


std::cout<< "TEST SPAN  N = 10 \n";
    Span mySpan(10);
try{
    for (unsigned int i = 0; i < mySpan.getN(); i++){
        mySpan.addNumber(i);
    }
    }catch(const std::exception& e){

        std::cout << "Erreur : "<< e.what() << std::endl;
    }


    for (unsigned int i = 0; i < mySpan.getVector().size() ; i++){
        std::cout << mySpan.getVector()[i] << std::endl;
    }

    std::cout<< "\nTEST ADDING TOO MUCH\n";

try{
    mySpan.addNumber(10);
}catch (const std::exception & e){
    std::cout<< "Erreur addNumber impossible: " << e.what()<< std::endl;
}




    std::cout<< "\nTEST longestSpan()\n";
    std::cout<< "\nlongestSpan() de mon span de 10 elements\n";
    int biggest = mySpan.longestSpan(); // mySpan a 10 elements 
    std::cout<< biggest<< std::endl; // le plus grand span

    Span spanOnly1(1); // span de seulement 1 element max
    spanOnly1.addNumber(5); // ajoute un element

    //affichage de mon span de 1 seul element
    for (unsigned int i = 0; i < spanOnly1.getVector().size() ; i++){
        std::cout << spanOnly1.getVector()[i] << std::endl;
    }
    // test de trouver le longestSpan donc renvoie une erreur
    try{
    spanOnly1.longestSpan();
    } catch (const std::exception& e){
        std::cout<< "function longestSpan() impossible because: " << e.what() << std::endl;
    }


    std::cout<< "\nTEST shortestSpan()\n";


    Span randomSpan(3);

    // Remplir le Span avec 10 nombres aléatoires entre 0 et 100
    std::srand(std::time(0));
    for (unsigned int i = 0; i < randomSpan.getN(); ++i) {
        int randomValue = std::rand() % 101;
        randomSpan.addNumber(randomValue);
        std::cout << "Ajouté : " << randomValue << std::endl;
    }

    try {
        int shortest = randomSpan.shortestSpan();
        std::cout << "Shortest span : " << shortest << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erreur : " << e.what() << std::endl;
    }


        
    std::cout<< "\nTEST fonction addNumbers\n";

    // Test avec un std::set
    std::set<int> mySet;
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
   // mySet.insert(40);    --a ajouter pour tester d'inserer un set de nombre trop grand et depasser N

    Span sp(5);
    sp.addNumber(1);
    sp.addNumber(2);

    // Ajout de tous les éléments du set d'un coup
    try{
        sp.addNumbers(mySet.begin(), mySet.end());
    } catch (const std::exception& e){
        std::cout<<"addNumbers fail: "<< e.what()<<std::endl;
    }

    // Affichage pour vérifier le contenu
    std::vector<int> v = sp.getVector();
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    // Test d’exception si on dépasse la capacité
    // try {
    //     std::set<int> bigSet;
    //     for (int i = 0; i < 10; ++i)
    //         bigSet.insert(i + 100);
    //     sp.addNumbers(bigSet.begin(), bigSet.end());
    // } catch (const std::exception& e) {
    //     std::cout << "Exception attrapée : " << e.what() << std::endl;
    // }


}