#pragma once
#include "Bureaucrat.hpp"
#include <string>
#include <iostream> 
#include <exception>

//execptions pour form
//

class AForm {

    private:
    
    const std::string name;
    bool isSigned;
    const int grade_sign;
    const int grade_ex;

    public :
    
  

    AForm(const std::string& name, int signGrade, int execGrade);
    AForm(const Form& other);
    virtual ~AForm();

    //fonction a implementer dans chaque classe concrete pour executer
    virtual void execute(const Bureaucrat const &executor);
  
      //fonction check d'execution dans execute
    void executeCheck(const Bureaucrat &executor) const;//executor le bureaucrat qui veut executer


    // Fonction pour signer le formulaire
    void beSigned(Bureaucrat const& bureaucrat);

        // Getters
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

        // Classes d'exceptions
    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw(); //virtual permet d'utiliser sa propre implementation
    };

        //ajout de l'exception not signed 
    class NotSignedException : public std::exception{
        virtual const char* what() const throw();
    };

        // Surcharge d'opérateur (déclaration)
    friend std::ostream& operator<<(std::ostream& os, const Form& form);
    

};