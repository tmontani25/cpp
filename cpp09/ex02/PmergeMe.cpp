#include "PmergeMe.hpp"
#include <algorithm>  // Pour std::find, std::distance

// Fonction qui parse et valide les arguments de la ligne de commande
// Retourne un vector d'entiers positifs
// Lance une exception si les entrées sont invalides
std::vector<int> parseNumbers(int argc, char **argv){
    std::vector<int> Vnumbers;

    // Parcourir tous les arguments (sauf argv[0] qui est le nom du programme)
    for(int i = 1; i < argc; i++){
        int num;
        std::string str = argv[i];

        // Vérifier que la chaîne n'est pas vide
        if (str.empty())
            throw std::runtime_error("Error");

        // Vérifier caractère par caractère que ce sont bien des chiffres
        // Cela rejette les nombres négatifs et les caractères non-numériques
        for (size_t j = 0; j < str.length(); j++) {
            if (!isdigit(str[j])) {
                throw std::runtime_error("Error");
            }
        }

        // Convertir la chaîne en entier
        std::stringstream ss(str);
        if (!(ss >> num)) // Si la conversion échoue, renvoyer une erreur
            throw std::runtime_error("Error");

        // Vérifier que le nombre est positif (sécurité supplémentaire)
        if (num < 0)
            throw std::runtime_error("Error");

        Vnumbers.push_back(num);
    }
    return Vnumbers;
}

// Fonction pour afficher les éléments d'un conteneur (utilisée pour "Before:")
template<typename Container>
void printContainer(const Container& container){
    for (size_t i = 0; i < container.size(); i++){
        std::cout << container[i];
        if (i < container.size() - 1)
            std::cout << " ";  // Espace entre les nombres
    }
    std::cout << std::endl;
}


// ÉTAPE 1 : Former des paires d'éléments consécutifs
// Exemple : [5, 2, 8, 1, 9, 3] devient [(5,2), (8,1), (9,3)]
// Si le nombre d'éléments est impair, le dernier est traité séparément
template<typename Container>
std::vector<std::pair<int, int> > formPairs(Container& container) {
    std::vector<std::pair<int, int> > pairs;

    // On parcourt le conteneur 2 par 2
    for (size_t i = 0; i < container.size() - 1; i += 2) {
        std::pair<int, int> p;
        p.first = container[i];
        p.second = container[i + 1];

        pairs.push_back(p);
    }
    return pairs;
}

// ÉTAPE 2 : Trier chaque paire localement
// Le plus petit va dans .first, le plus grand dans .second
// Exemple : (5,2) devient (2,5), (8,1) devient (1,8)
void    sortPairs(std::vector<std::pair<int, int> > &pairs){
    for (size_t i = 0; i < pairs.size(); i++){
        if(pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
}

// ÉTAPE 3a : Extraire tous les "grands" éléments des paires
// Ces éléments seront triés récursivement
// Exemple : [(2,5), (1,8), (3,9)] → [5, 8, 9]
std::vector<int> extractMax(std::vector<std::pair<int, int> > &pairs){
    std::vector<int> maxList;
    for (size_t i = 0; i < pairs.size(); i++){
        maxList.push_back(pairs[i].second);
    }
    return maxList;
}

// ÉTAPE 3b : Extraire tous les "petits" éléments des paires
// Ces éléments seront insérés après le tri des "grands"
// Exemple : [(2,5), (1,8), (3,9)] → [2, 1, 3]
std::vector<int> extractMin(std::vector<std::pair<int, int> > &pairs){
    std::vector<int> minList;
    for (size_t i = 0; i < pairs.size(); i++){
        minList.push_back(pairs[i].first);
    }
    return minList;
}


// INSERTION BINAIRE : Insérer un élément dans un conteneur trié
// La recherche est limitée jusqu'à maxIndex (optimisation de Ford-Johnson)
// Cela garantit O(log n) comparaisons
template <typename Container>
void binaryInsert(Container &sortedMax, int minToInsert, int maxIndex){
    // lower_bound trouve la première position où insérer pour garder l'ordre
    typename Container::iterator pos = std::lower_bound(
        sortedMax.begin(),
        sortedMax.begin() + maxIndex + 1,  // Limite : on sait que min ≤ max
        minToInsert
    );

    sortedMax.insert(pos, minToInsert);
}

// TROUVER L'INDEX : Localiser un élément dans le conteneur trié
// Utilisé pour trouver où se trouve le "grand" d'une paire
// afin de limiter la recherche binaire du "petit"
template <typename Container>
int findIndex(Container &sortedMax, int associatedMax){
    typename Container::iterator pos = std::find(
        sortedMax.begin(),
        sortedMax.end(),
        associatedMax
    );

    // Convertir l'itérateur en index numérique
    return std::distance(sortedMax.begin(), pos);
}


// ÉTAPE 5 : Insérer les "petits" dans la liste des "grands" triée
// Pour chaque paire (min, max), on sait que min ≤ max
// Donc on limite la recherche binaire jusqu'à la position de max
// Cela réduit le nombre de comparaisons (optimisation Ford-Johnson)
template <typename Container>
void insertMin(std::vector<std::pair<int, int> >& pairs, Container& sortedMax) {
    for (size_t i = 0; i < pairs.size(); i++) {
        int minToInsert = pairs[i].first;     // Le "petit" à insérer
        int associatedMax = pairs[i].second;   // Son "grand" associé

        // Trouver où se trouve le "grand" dans la liste triée
        int maxIndex = findIndex(sortedMax, associatedMax);

        // Insérer le "petit" en ne cherchant que jusqu'à son "grand"
        binaryInsert(sortedMax, minToInsert, maxIndex);
    }
}


// Insérer un élément isolé (l'élément impair s'il existe) dans le conteneur trié
// Utilise la recherche binaire sur tout le conteneur
template <typename Container>
void insertSorted(Container& sortedContainer, int element) {
    // Trouver la position d'insertion avec recherche binaire
    typename Container::iterator pos = std::lower_bound(
        sortedContainer.begin(),
        sortedContainer.end(),
        element
    );

    sortedContainer.insert(pos, element);
}

// ═══════════════════════════════════════════════════════════════════════════
// ALGORITHME FORD-JOHNSON (MERGE-INSERT SORT)
// ═══════════════════════════════════════════════════════════════════════════
// Algorithme de tri optimal qui minimise le nombre de comparaisons
// Complexité : O(n log n) avec un nombre de comparaisons proche du minimum théorique
//
// PRINCIPE :
// 1. Former des paires et trier chaque paire localement
// 2. Extraire les "grands" et les trier récursivement (RÉCURSION)
// 3. Insérer les "petits" avec recherche binaire optimisée
// 4. Gérer l'élément impair s'il existe
//
// Exemple : [5, 2, 8, 1, 9, 3, 7, 4]
//   Paires : [(2,5), (1,8), (3,9), (4,7)]
//   Max : [5, 8, 9, 7] → tri récursif → [5, 7, 8, 9]
//   Insertion des min : [2, 1, 3, 4] → [1, 2, 3, 4, 5, 7, 8, 9]
// ═══════════════════════════════════════════════════════════════════════════
template <typename Container>
Container mergeInsertSort(Container& container){

    // Variables pour gérer l'élément impair (s'il y en a un)
    bool isImpair = false;
    int impairElement = 0;

    // Cas de base : conteneur vide ou avec 1 élément (déjà trié)
    if (container.size() <= 1)
        return container;

    // Si nombre impair d'éléments, on met le dernier de côté
    if (container.size() % 2 != 0){
        isImpair = true;
        impairElement = container.back();
    }

    // ÉTAPE 1 : Former les paires d'éléments
    std::vector<std::pair<int , int> > pairs = formPairs(container);

    // ÉTAPE 2 : Trier chaque paire (min dans .first, max dans .second)
    sortPairs(pairs);

    // ÉTAPE 3 : Extraire la liste des "grands"
    std::vector<int> maxList = extractMax(pairs);

    // Convertir en conteneur du bon type (vector ou deque)
    Container maxContainer(maxList.begin(), maxList.end());

    // ÉTAPE 4 : APPEL RÉCURSIF pour trier les "grands"
    // C'est le cœur de l'algorithme !
    Container sortedMax = mergeInsertSort(maxContainer);

    // ÉTAPE 5 : Insérer les "petits" avec recherche binaire optimisée
    insertMin(pairs, sortedMax);

    // ÉTAPE 6 : Insérer l'élément impair s'il existe
    if (isImpair){
        insertSorted(sortedMax, impairElement);
    }

    return sortedMax;
}


