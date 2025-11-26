#include <string>
#include <iostream>
#include <stack>

// faire un stack container iterable

template <typename T>
class MutantStack : public std::stack<T>{ // permet d'heriter du fonctionnement de stack push() pop() top()...
                                            // stack contient un deque c qui est un element prive du container
    public:
    MutantStack(): std::stack<T>(){}
    MutantStack(const MutantStack &other) : std::stack<T>(other){}
    MutantStack &operator=(const MutantStack &other){
        if (*this != &other)
            std::stack<T>:: operator=(other);
        return *this;
    }
    ~MutantStack(){}

    // iterator
    typedef typename std::stack<T>::container_type::iterator iterator;

    // begin et end
    typename std::stack<T>::container_type::iterator begin() {
        return this->c.begin();
    }

    typename std::stack<T>::container_type::iterator end() {
        return this->c.end();
    }



};


// int main()
// {
// MutantStack<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
// MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite) {
//     std::cout << *it << std::endl;
// ++it; }
// std::stack<int> s(mstack); return 0;
// }