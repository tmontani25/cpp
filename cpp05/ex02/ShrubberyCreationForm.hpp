#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#pragma once
#include "AForm.hpp"
#include <fstream>
#include <stdexcept>

class ShrubberyCreationForm : public AForm {
private:
    const std::string _target;  // Même logique que Presidential
    void writeTreeToFile() const;  // Méthode privée pour arbre
    ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);// private non copiable

public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    virtual ~ShrubberyCreationForm();

    void execute(Bureaucrat const &executor) const;
};

#endif