#include "PmergeMe.hpp"
#include <algorithm>  // Pour std::find, std::distance

// ═══════════════════════════════════════════════════════════════════════════
// GÉNÉRATION DE LA SÉQUENCE DE JACOBSTHAL
// ═══════════════════════════════════════════════════════════════════════════
// Les nombres de Jacobsthal : 0, 1, 1, 3, 5, 11, 21, 43, 85, ...
// Formule : J(n) = J(n-1) + 2*J(n-2)
// Ces nombres déterminent l'ordre optimal d'insertion dans Ford-Johnson
std::vector<size_t> generateJacobsthalSequence(size_t n) {
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    while (jacobsthal.back() < n) {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

// ═══════════════════════════════════════════════════════════════════════════
// GÉNÉRATION DE L'ORDRE D'INSERTION DE JACOBSTHAL
// ═══════════════════════════════════════════════════════════════════════════
// L'ordre d'insertion pour n éléments :
// - Groupe 1: index 0 (b1)
// - Groupe 2: index 2, 1 (b3, b2)
// - Groupe 3: index 4, 3 (b5, b4)
// - Groupe 4: index 10, 9, 8, 7, 6, 5 (b11, b10, ..., b6)
// Cet ordre minimise le nombre de comparaisons
std::vector<size_t> getJacobsthalInsertionOrder(size_t n) {
    if (n == 0)
        return std::vector<size_t>();

    std::vector<size_t> order;
    std::vector<size_t> jacobsthal = generateJacobsthalSequence(n);

    // Le premier élément (index 0) est toujours inséré en premier
    order.push_back(0);

    // Parcourir les groupes de Jacobsthal
    for (size_t k = 2; k < jacobsthal.size(); k++) {
        size_t current = jacobsthal[k];
        size_t prev = jacobsthal[k - 1];

        // Insérer de current vers prev+1 (en décroissant)
        // mais limité à n-1 (indices valides)
        size_t start = (current > n) ? n : current;

        for (size_t i = start; i > prev; i--) {
            if (i > 0 && i <= n) {
                order.push_back(i - 1); // -1 car indices commencent à 0
            }
        }
    }

    return order;
}

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
        if (!(ss >> num)) // Si la conversion échoue, renvoyer une erreur stream = false
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


// ═══════════════════════════════════════════════════════════════════════════
// RECONSTRUCTION DES PAIRES ORDONNÉES
// ═══════════════════════════════════════════════════════════════════════════
// Après le tri récursif des max, on doit reconstruire les paires
// dans l'ordre des max triés pour maintenir l'association min/max
template <typename Container>
std::vector<std::pair<int, int> > reorderPairs(
    std::vector<std::pair<int, int> >& originalPairs,
    Container& sortedMax)
{
    std::vector<std::pair<int, int> > orderedPairs;

    // Pour chaque max dans l'ordre trié, retrouver sa paire originale
    for (size_t i = 0; i < sortedMax.size(); i++) {
        int maxVal = sortedMax[i];

        // Chercher la paire originale avec ce max
        for (size_t j = 0; j < originalPairs.size(); j++) {
            if (originalPairs[j].second == maxVal) {
                orderedPairs.push_back(originalPairs[j]);
                // Marquer comme utilisé pour éviter les doublons
                originalPairs[j].second = -1;
                break;
            }
        }
    }
    return orderedPairs;
}

// ═══════════════════════════════════════════════════════════════════════════
// ÉTAPE 5 : INSERTION AVEC L'ORDRE DE JACOBSTHAL (VRAI FORD-JOHNSON)
// ═══════════════════════════════════════════════════════════════════════════
// L'ordre d'insertion de Jacobsthal minimise le nombre de comparaisons
// car il exploite la propriété que chaque insertion utilise au maximum
// ⌈log₂(k)⌉ comparaisons où k est la taille de la zone de recherche
template <typename Container>
void insertMinJacobsthal(std::vector<std::pair<int, int> >& orderedPairs, Container& mainChain) {
    if (orderedPairs.empty())
        return;

    // Le premier min (associé au plus petit max) est inséré au début
    // car on sait que min_0 <= max_0 et max_0 est en position 0
    mainChain.insert(mainChain.begin(), orderedPairs[0].first);

    if (orderedPairs.size() == 1)
        return;

    // Générer l'ordre d'insertion de Jacobsthal pour les éléments restants
    std::vector<size_t> insertionOrder = getJacobsthalInsertionOrder(orderedPairs.size() - 1);

    for (size_t i = 0; i < insertionOrder.size(); i++) {
        // L'index dans orderedPairs (décalé de 1 car on a déjà inséré le premier)
        size_t pairIndex = insertionOrder[i] + 1;

        if (pairIndex >= orderedPairs.size())
            continue;

        int minToInsert = orderedPairs[pairIndex].first;
        int associatedMax = orderedPairs[pairIndex].second;

        // Trouver la position du max associé dans la chaîne principale
        int maxIndex = findIndex(mainChain, associatedMax);

        // La limite de recherche : on sait que min <= max
        // donc on cherche uniquement jusqu'à la position du max
        binaryInsert(mainChain, minToInsert, maxIndex);
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
// ALGORITHME FORD-JOHNSON (MERGE-INSERT SORT) - VRAIE IMPLÉMENTATION
// ═══════════════════════════════════════════════════════════════════════════
// Algorithme de tri optimal qui minimise le nombre de comparaisons
// Complexité : O(n log n) avec un nombre de comparaisons proche du minimum théorique
//
// PRINCIPE :
// 1. Former des paires et trier chaque paire localement
// 2. Extraire les "grands" et les trier récursivement (RÉCURSION)
// 3. Reconstruire l'association min/max après le tri
// 4. Insérer les "petits" selon l'ORDRE DE JACOBSTHAL (clé de Ford-Johnson)
// 5. Gérer l'élément impair s'il existe
//
// L'ordre de Jacobsthal (1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, ...)
// garantit que chaque insertion utilise au maximum ⌈log₂(k)⌉ comparaisons
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
    std::vector<std::pair<int, int> > pairs = formPairs(container);

    // ÉTAPE 2 : Trier chaque paire (min dans .first, max dans .second)
    sortPairs(pairs);

    // Copie des paires pour la reconstruction après tri
    std::vector<std::pair<int, int> > pairsCopy = pairs;

    // ÉTAPE 3 : Extraire la liste des "grands"
    std::vector<int> maxList = extractMax(pairs);

    // Convertir en conteneur du bon type (vector ou deque)
    Container maxContainer(maxList.begin(), maxList.end());

    // ÉTAPE 4 : APPEL RÉCURSIF pour trier les "grands"
    Container sortedMax = mergeInsertSort(maxContainer);

    // ÉTAPE 5 : Reconstruire les paires dans l'ordre des max triés
    // Cela maintient l'association entre chaque min et son max
    std::vector<std::pair<int, int> > orderedPairs = reorderPairs(pairsCopy, sortedMax);

    // ÉTAPE 6 : Insérer les "petits" selon l'ordre de JACOBSTHAL
    // C'est LA différence clé avec une implémentation naïve !
    insertMinJacobsthal(orderedPairs, sortedMax);

    // ÉTAPE 7 : Insérer l'élément impair s'il existe
    if (isImpair){
        insertSorted(sortedMax, impairElement);
    }

    return sortedMax;
}


