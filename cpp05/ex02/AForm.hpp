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
    bool is_signed;
    const int grade_sign;
    const int grade_ex;

    protected:
    virtual void action() const = 0; // <-- méthode pure-virtuelle : rend la classe abstraite

    public:

    AForm(const std::string& name, int signGrade, int execGrade);
    AForm(const Form& other);
    virtual ~AForm();

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
        virtual const char* what() const throw();
    };

        // Surcharge d'opérateur (déclaration)
    friend std::ostream& operator<<(std::ostream& os, const Form& form);
    

};