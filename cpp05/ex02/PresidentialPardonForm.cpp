#include "PresidentialPardonForm.hpp"

//********************************* methodes forme canonique ****** */
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
    : AForm("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
    : AForm(other), _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

//*** */ implementation de la methode virtuelle pure execute de AForm */
void PresidentialPardonForm::execute(const Bureaucrat &executor)const{

    executeCheck(executor); // lance si besoin les exceptions (grade ok et signed)
    //le bureaucrat execute le form

    std::cout << executor << " executed form" << std::endl;
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

