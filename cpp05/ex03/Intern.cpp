#include "Intern.hpp"

Intern::Intern(void) {
}

Intern::Intern(Intern const &other) {
    (void)other;  // L'intern n'a pas d'attributs à copier
}

Intern::~Intern(void) {
}

Intern &Intern::operator=(Intern const &other) {
    (void)other;  // L'intern n'a pas d'attributs à assigner
    return *this;
}

const char* Intern::UnknownFormException::what() const throw() {
    return "Unknown form type";
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) {
    if (formName == "presidential pardon") {
        std::cout << "Intern creates presidential pardon form" << std::endl;
        return new PresidentialPardonForm(target);
    }
    else if (formName == "robotomy request") {
        std::cout << "Intern creates robotomy request form" << std::endl;
        return new RobotomyRequestForm(target);
    }
    else if (formName == "shrubbery creation") {
        std::cout << "Intern creates shrubbery creation form" << std::endl;
        return new ShrubberyCreationForm(target);
    }
    
    throw UnknownFormException();
    return NULL;  // Ne sera jamais atteint à cause du throw
}