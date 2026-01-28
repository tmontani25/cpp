#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <vector>
#include <deque>
#include <utility>
#include <ctime>        // Pour mesurer le temps en C++98
#include <sys/time.h>   // Pour gettimeofday (plus précis)

// ═══════════════════════════════════════════════════════════════
// DÉCLARATIONS DES FONCTIONS
// ═══════════════════════════════════════════════════════════════

// Parse et valide les arguments de la ligne de commande
std::vector<int> parseNumbers(int argc, char **argv);

// Affiche un conteneur (vector ou deque)
template<typename Container>
void printContainer(const Container& container);

// Algorithme Ford-Johnson (Merge-Insert Sort)
template <typename Container>
Container mergeInsertSort(Container& container);

// Fonctions utilitaires pour le tri
void sortPairs(std::vector<std::pair<int, int> > &pairs);
std::vector<int> extractMax(std::vector<std::pair<int, int> > &pairs);
std::vector<int> extractMin(std::vector<std::pair<int, int> > &pairs);



#include "PmergeMe.cpp"

#endif
