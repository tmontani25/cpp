#include "Bureaucrat.hpp"


//constructeur de copie
Bureaucrat::Bureaucrat(Bureaucrat const &other) : grade(other.grade), name(other.name) {}

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

    //getters

    int Bureaucrat::getGrade()const{
        return this->grade;
    }
    const std::string &Bureaucrat::getName() const {
        return this->name;
    }

// Implémentation de what() pour GradeTooHighException
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high: grade cannot be higher than 1";
}

// Implémentation de what() pour GradeTooLowException
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low: grade cannot be lower than 150";
}

// surcharge operateur << 
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.name << ", bureaucrat grade " << b.grade;
    return os;
}

