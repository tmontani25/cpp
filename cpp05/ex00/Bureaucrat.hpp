#pragma once
#include <string>
#include <iostream> 

//class bureaucrat simple avec un grade
// membres qui permette de verifier le grade

class Bureaucrat {
    private:
        int grade;
        const std::string  name;
    public:
        Bureaucrat(const std::string &n, int g) : name(n), grade(g){}
        //copie
        Bureaucrat(Bureaucrat const &other){}
        

        //operateur

};