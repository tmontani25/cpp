#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#pragma once
#include <string>
#include <iostream> 
#include <exception>

class Form;  // Forward declaration pour la fonction signForm


//class bureaucrat simple avec un grade
// membres qui permette de verifier le grade
// creer des versions de what pour chaque class exception

class Bureaucrat {
    private:
        int grade;
        const std::string  name;

        //operateur= interdit private on veut pas copier de bureaucrat
        Bureaucrat &operator=(const Bureaucrat &other);

    public:
        //constructeur
        Bureaucrat(const std::string &n, int g) : grade(g), name(n){
                    // Vérification du grade ici
        if (g < 1)
            throw GradeTooHighException();
        if (g > 150)
            throw GradeTooLowException();
        }
        //copie
        Bureaucrat(Bureaucrat const &other) __attribute__((unused));
        ~Bureaucrat(){}

        //methodes
        void signForm(AForm& form);
            //ajout methode execution
        void executeForm(AForm& form);
        void incrementGrade();
        void decrementGrade();
        friend std::ostream& operator<<(std::ostream &os, const Bureaucrat& b);


        class GradeTooHighException : public std::exception {
            public :
                //declaration de what specifique a l'exception 
                //virtual permet de redefinir what dans ma class
                //c'est une methode de std :: exception que je redifini
                //grace a virtual
                virtual const char * what() const throw();

        };

        class GradeTooLowException : public std::exception {
        public:
            //decla what specifique a l'exception 
            virtual const char* what() const throw();
        };

        //getters
        int getGrade() const;
        const std :: string &getName() const; //implementation .cpp

};
#endif