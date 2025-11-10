#ifndef INTERN_HPP
#define INTERN_HPP
#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
    public:
        Intern(void);                               // Constructeur par défaut
        Intern(Intern const &other);                // Constructeur de copie
        ~Intern(void);                              // Destructeur
        Intern &operator=(Intern const &other);     // Opérateur d'assignation

        // Méthode principale pour créer un formulaire
        AForm *makeForm(std::string const &formName, std::string const &target);

        // Exception pour formulaire inconnu
        class UnknownFormException : public std::exception {
            virtual const char* what() const throw();
        };
};

#endif