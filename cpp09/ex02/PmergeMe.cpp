#include "PmergeMe.hpp"

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


template <typename Container>
void mergeInsertSort(Container& container){

    if (container.size() <= 1)
        return;
    std::vector<std::pair<int , int> > pairs = formPairs(container);
    
    std::cout << "before sort\n";
    for(size_t i = 0; i < pairs.size(); i++){
        std::cout<< pairs[i].first << pairs[i].second << std::endl;
    }

    sortPairs(pairs);
    std::cout << "after sort\n";
        for(size_t i = 0; i < pairs.size(); i++){
        std::cout<< pairs[i].first << pairs[i].second << std::endl;
    }

    std::vector<int> maxList = extractMax(pairs);
    // mergeInsertSort(maxList);

    // insertMin();


    
    
    
    
    
    
    // TODO : Implémenter l'algorithme Ford-Johnson
    // Étapes :
    // 1. Grouper par paires
    // 2. Trier chaque paire
    // 3. Trier récursivement les plus grands
    // 4. Insérer les plus petits avec recherche binaire
    }


