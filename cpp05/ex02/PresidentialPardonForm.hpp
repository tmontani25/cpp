#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

    private:
    const std::string _target;
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(PresidentialPardonForm const &other);
    virtual ~PresidentialPardonForm(void);

 // privé et non implémenté pour empêcher l'assignation

    

    //version de action
    virtual void execute(Bureaucrat const &executor) const;

};

#endif