#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

    public:
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm const &other);

    //version de action
    virtual void execute(const Bureaucrat const &executor) const;




};

#endif