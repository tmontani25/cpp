#include "PmergeMe.hpp"


int main(int argc, char **argv){

    /*try{
    checkInput(argv)
    }catch
    
    */
    
    std::vector<int> Vnumbers = parseNumbers(argc, argv);
    std::cout << "print before\n";
    printBefore(Vnumbers);
    std::deque<int> Dnumbers(Vnumbers.begin(), Vnumbers.end());
    
    std::vector<int> sortedV = mergeInsertSort(Vnumbers);
    std::deque<int> sortedD = mergeInsertSort(Dnumbers);


    std::cout << "\nprint after\n";
    for(size_t i = 0; i < sortedV.size(); i++){

        std::cout << sortedV[i] << std::endl;
    }
    

    // TODO: Afficher les résultats et les temps de tri

    return 0;
}


// mergeInsertSort(container) {
//     1. Créer des paires
//     2. Trier chaque paire localement
//     3. Extraire tous les max → maxList
//     4. mergeInsertSort(maxList)  ← RÉCURSIF !
//     5. Insérer les min dans maxList trié
// }

// Début : [5, 2, 8, 1, 9, 3, 7, 4]

// Paires : [2,5]  [1,8]  [3,9]  [4,7]

// Extraire les max : [5, 8, 9, 7]

// → APPEL RÉCURSIF : trier [5, 8, 9, 7] avec le MÊME algorithme !
  
//   Sous-problème :
//   Paires : [5,8]  [7,9]
//   Max : [8, 9]
//   Tri récursif de [8, 9] → déjà trié !
//   Insertion : [8, 9] puis insérer 5 et 7
//   Résultat : [5, 7, 8, 9]

// Retour au problème principal avec les max triés : [5, 7, 8, 9]



// std::vector<int> Vnumbers = parseNumbers(argc, argv);
// std::deque<int> Dnumbers(Vnumbers.begin(), Vnumbers.end());

// // Comparaison de performances :
// auto start1 = std::chrono::high_resolution_clock::now();
// std::vector<int> sortedV = mergeInsertSort(Vnumbers);
// auto end1 = std::chrono::high_resolution_clock::now();

// auto start2 = std::chrono::high_resolution_clock::now(); 
// std::deque<int> sortedD = mergeInsertSort(Dnumbers);
// auto end2 = std::chrono::high_resolution_clock::now();