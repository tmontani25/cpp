#include "PmergeMe.hpp"
#include <algorithm>  // Pour std::find, std::distance

std::vector<int> parseNumbers(int argc, char **argv){
    std::vector<int> Vnumbers;


    for(int i = 1; i < argc; i++){
        int num;
        std::string str = argv[i];
        for (size_t j = 0; j < str.length(); j++) {
            if (!isdigit(str[j])) {
                throw std::runtime_error("Error");
            }
        }

        std::stringstream ss(str);
        if (!(ss >> num)) //num etant un int si la valeur lue dans ss n'est pas un int ca renvoie NULL
            throw std::runtime_error("Error");

        Vnumbers.push_back(num);
    }
    return Vnumbers;


}

void printBefore(std::vector<int> Vnumbers){

    for (size_t i = 0; i < Vnumbers.size(); i++){
        std::cout << Vnumbers[i] << std::endl;
    }
}


template<typename Container>
std::vector<std::pair<int, int> > formPairs(Container& container) {
    std::vector<std::pair<int, int> > pairs;
    

    for (size_t i = 0; i < container.size() - 1; i += 2) { //saute de 2 en 2
        // Créer une paire et l'ajouter
        std::pair<int, int> p;
        p.first = container[i];
        p.second = container[i + 1];
        
        pairs.push_back(p);  // ← Ajoute à la fin du vector
    }
    return pairs;
}

void    sortPairs(std::vector<std::pair<int, int> > &pairs){

    for (size_t i = 0; i < pairs.size(); i++){
        if(pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
}

std::vector<int> extractMax(std::vector<std::pair<int, int> > &pairs){

    std::vector<int> maxList;
    for (size_t i = 0; i < pairs.size(); i++){
        maxList.push_back(pairs[i].second);
    }
    return maxList;
}
std::vector<int> extractMin(std::vector<std::pair<int, int> > &pairs){

    std::vector<int> minList;
    for (size_t i = 0; i < pairs.size(); i++){
        minList.push_back(pairs[i].first);
    }
    return minList;
}


template <typename Container>
void binaryInsert(Container &sortedMax, int minToInsert, int maxIndex){
    // Recherche binaire limitée jusqu'à maxIndex
    typename Container::iterator pos = std::lower_bound(
        sortedMax.begin(), 
        sortedMax.begin() + maxIndex + 1,  // Limite la recherche !
        minToInsert
    );
    
    // Insérer à cette position
    sortedMax.insert(pos, minToInsert);
}
template <typename Container>
int findIndex(Container &sortedMax, int associatedMax){
    // Trouver l'élément exact avec std::find
    typename Container::iterator pos = std::find(
        sortedMax.begin(), 
        sortedMax.end(), 
        associatedMax
    );
    
    // Convertir l'itérateur en index
    return std::distance(sortedMax.begin(), pos);
}


template <typename Container>
void insertMin(std::vector<std::pair<int, int> >& pairs, Container& sortedMax) {
    for (size_t i = 0; i < pairs.size(); i++) {
        int minToInsert = pairs[i].first;   // Le minimum à insérer
        int associatedMax = pairs[i].second; // Son maximum associé
        
        // Trouver l'index de associatedMax dans sortedMax
        int maxIndex = findIndex(sortedMax, associatedMax);
        
        // Insérer minToInsert par recherche binaire
        // (en sachant qu'il doit être ≤ associatedMax)
        binaryInsert(sortedMax, minToInsert, maxIndex);
    }
}


template <typename Container>
void insertSorted(Container& sortedContainer, int element) {
    // En C++98 : type explicite pour l'itérateur
    typename Container::iterator pos = std::lower_bound(
        sortedContainer.begin(), 
        sortedContainer.end(), 
        element
    );
    
    // Insère l'élément à cette position
    sortedContainer.insert(pos, element);
}

template <typename Container>
Container mergeInsertSort(Container& container){
    
    bool isImpair = false;
    int impairElement = 0;

    if (container.size() <= 1)
        return container;
    if (container.size() % 2 != 0){
        isImpair = true;
        impairElement = container.back();  // Pas de "int" - on assigne à la variable existante
    }

    std::vector<std::pair<int , int> > pairs = formPairs(container);

   sortPairs(pairs);  // sortPairs modifie pairs en place
    std::cout << "\npairs formed\n";
        for(size_t i = 0; i < pairs.size(); i++){
        std::cout<< pairs[i].first << pairs[i].second << std::endl;
    }

    // std::vector<int> minList = extractMin(pairs);
    std::vector<int> maxList = extractMax(pairs);
    

    Container maxContainer(maxList.begin(), maxList.end());

    std::cout << "\nmax container\n";
    for (size_t i = 0; i < maxContainer.size(); i++){
        std::cout << maxContainer[i];
    }
    Container sortedMax = mergeInsertSort(maxContainer);

    insertMin(pairs, sortedMax);
    if (isImpair){
        std::cout << "\n impair element\n\n";
        std::cout << impairElement << "\n" << std::endl;
        insertSorted(sortedMax, impairElement);
    }
    
    return sortedMax;  // Temporaire - manque encore l'insertion
}


