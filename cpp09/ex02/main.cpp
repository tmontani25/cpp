#include "PmergeMe.hpp"

// ═══════════════════════════════════════════════════════════════
// Fonction pour obtenir le temps actuel en microsecondes
// Utilise gettimeofday qui est compatible C++98
// ═══════════════════════════════════════════════════════════════
double getTimeInMicroseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

int main(int argc, char **argv){

    // ═══════════════════════════════════════════════════════════════
    // GESTION DES ERREURS
    // ═══════════════════════════════════════════════════════════════
    if (argc < 2) {
        std::cerr << "Error: no arguments provided" << std::endl;
        std::cerr << "Usage: ./PmergeMe <positive integers>" << std::endl;
        return 1;
    }

    try {
        // ═══════════════════════════════════════════════════════════
        // PARSING DES ARGUMENTS
        // ═══════════════════════════════════════════════════════════
        std::vector<int> Vnumbers = parseNumbers(argc, argv);

        // Créer une deque avec les mêmes valeurs
        std::deque<int> Dnumbers(Vnumbers.begin(), Vnumbers.end());

        // ═══════════════════════════════════════════════════════════
        // AFFICHAGE DE LA SÉQUENCE AVANT LE TRI
        // ═══════════════════════════════════════════════════════════
        std::cout << "Before:  ";
        printContainer(Vnumbers);

        // ═══════════════════════════════════════════════════════════
        // TRI AVEC std::vector ET MESURE DU TEMPS
        // ═══════════════════════════════════════════════════════════
        double startV = getTimeInMicroseconds();
        std::vector<int> sortedV = mergeInsertSort(Vnumbers);
        double endV = getTimeInMicroseconds();
        double timeV = endV - startV;

        // ═══════════════════════════════════════════════════════════
        // TRI AVEC std::deque ET MESURE DU TEMPS
        // ═══════════════════════════════════════════════════════════
        double startD = getTimeInMicroseconds();
        std::deque<int> sortedD = mergeInsertSort(Dnumbers);
        double endD = getTimeInMicroseconds();
        double timeD = endD - startD;

        // ═══════════════════════════════════════════════════════════
        // AFFICHAGE DE LA SÉQUENCE APRÈS LE TRI
        // ═══════════════════════════════════════════════════════════
        std::cout << "After:   ";
        printContainer(sortedV);

        // ═══════════════════════════════════════════════════════════
        // AFFICHAGE DES TEMPS D'EXÉCUTION
        // ═══════════════════════════════════════════════════════════
        std::cout << "Time to process a range of " << sortedV.size()
                  << " elements with std::vector : " << timeV << " us" << std::endl;

        std::cout << "Time to process a range of " << sortedD.size()
                  << " elements with std::deque  : " << timeD << " us" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}