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

std::vector<int> parseNumbers(int argc, char **argv);
void printBefore(std::vector<int> Vnumbers);

template <typename Container>
void mergeInsertSort(Container& container);

void sortPairs(std::vector<std::pair<int, int> > &pairs);
std::vector<int> extractMax(std::vector<std::pair<int, int> > &pairs);

#include "PmergeMe.cpp"

#endif
