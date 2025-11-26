#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <set>

// class qui stocke des int
// maximum de int N

class Span{

    private:
    unsigned int N;
    std::vector<int> v;

    public :
    Span(int n) : N(n){
        if (n <= 0){
            throw std::invalid_argument("la capacite du span doit etre > 0\n");
        }
    }
       // constructeur de copie
     Span(const Span &other) : N(other.N), v(other.v) {}

    Span &operator=(const Span &other){
        if (this != &other){
            this->N = other.N;
            this->v = other.v;
        }
        return *this;
    }
 

    // constructeur assignation =
    // destructeur

    void addNumber(int num){
        unsigned int size = v.size();
        if (size + 1 <= N){
            v.push_back(num);
        }
        else throw std::overflow_error("overflow\n");
    }

    //getter
    const std::vector<int> getVector(){
        return v;
    }
    unsigned int getN(){
        return(N);
    }

    //fonctions

    int longestSpan(){
        if (this->v.size() <= 0 || this->v.size() ==1)
            throw std::logic_error ("le span doit contenir au moins 2 elements\n");
        int min = *std::min_element(v.begin(), v.end());
        int max = *std::max_element(v.begin(), v.end());
        return max - min;
    }

    int shortestSpan()
    {
        if (this->v.size() <= 0 || this->v.size() ==1)
            throw std::logic_error ("le span doit contenir au moins 2 elements\n");
        
        std::vector<int> vcopy = v;
        std::sort(vcopy.begin(), vcopy.end());
        int minSpan = std::abs(vcopy[1] - vcopy[0]); // comparaison de la premiere paire
        for(size_t i = 1; i < vcopy.size() - 1; i++){
            int diff = std::abs(vcopy[i+1] - vcopy[1]); // valeure absolue de la diffence entre le 2e element et le 3e, 3e et 4e ainsi de suite
            if (diff < minSpan){
                minSpan = diff;
            }
        }
        return minSpan;
        
    }

    template <typename inputIt>
    void addNumbers(inputIt begin, inputIt end){ //supporte tout type d'iterateur

        // checker combien de nombres
        long len = std::distance(begin, end);

        //checker si on peut le rentrer sans depasser N
        if (v.size() + len > N){
            throw std::overflow_error("depasse la capacité du span -> overflow error");
        }

            std::copy(begin, end, std::back_inserter(v));
    }

};