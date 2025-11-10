#include "RobotomyRequestForm.hpp"

bool RobotomyRequestForm::_seeded = false;

RobotomyRequestForm::RobotomyRequestForm(void) 
    : AForm("Robotomy Request", 72, 45), _target("default") {
    if (!_seeded) {
        srand(time(NULL));
        _seeded = true;
    }
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
    : AForm("Robotomy Request", 72, 45), _target(target) {
    if (!_seeded) { //on lance une seule fois
        srand(time(NULL)); //genere 
        _seeded = true;
    }
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

// methode execute

void RobotomyRequestForm::execute(Bureaucrat const &executor)const{

    executeCheck(executor);

    std::cout << "* VRRRRRRR... DRRRRRRR... perceuse ! *" << std::endl;
        if (rand() % 2) {  // 50% de chance (0 ou 1)
        std::cout << _target << " a été robotomisé avec succès" << std::endl;
    } else {
        std::cout << "La robotomisation de " << _target << " a échoué" << std::endl;
    }
}





