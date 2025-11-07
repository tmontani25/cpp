#include "PresidentialPardonForm.hpp"


PresidentialPardonForm :: PresidentialPardonForm() : AForm("presidential Pardon", 25, 5){}

//*** */ implementation de la methode virtuelle pure execute de AForm */
void PresidentialPardonForm::execute(const Bureaucrat &executor)const{

    executeCheck(executor); // lance si besoin les exceptions
    //le bureaucrat execute le form

    std::cout << executor << "executed form"<<std::endl;
    std:: cout << "target is pardoned" <<std::endl;
}

