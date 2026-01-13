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

// Structure pour garder l'association max-min pendant Ford-Johnson
struct PairInfo {
    int max;
    int min;
    
    // Constructeur pour faciliter la création
    PairInfo(int maximum, int minimum) : max(maximum), min(minimum) {}
}; 

std::vector<int> parseNumbers(int argc, char **argv);
void printBefore(std::vector<int> Vnumbers);

template <typename Container>
Container mergeInsertSort(Container& container);  // ← Corrigé pour retourner Container

void sortPairs(std::vector<std::pair<int, int> > &pairs);
std::vector<int> extractMax(std::vector<std::pair<int, int> > &pairs);
std::vector<int> extractMin(std::vector<std::pair<int, int> > &pairs);



#include "PmergeMe.cpp"

#endif
