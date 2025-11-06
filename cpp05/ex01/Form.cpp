#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructeur
Form::Form(const std::string& n, int signGrade, int execGrade) 
    : name(n), is_signed(false), grade_sign(signGrade), grade_ex(execGrade)
{
    if (grade_sign < 1 || grade_ex < 1)
        throw Form::GradeTooHighException();
    if (grade_sign > 150 || grade_ex > 150)
        throw Form::GradeTooLowException();
}

// Constructeur de copie
Form::Form(const Form& other)
    : name(other.name), is_signed(other.is_signed), 
      grade_sign(other.grade_sign), grade_ex(other.grade_ex)
{
}

// Destructeur
Form::~Form()
{
}

// Getters
const std::string& Form::getName() const {
    return this->name;
}

bool Form::getIsSigned() const {
    return this->is_signed;
}

int Form::getGradeToSign() const {
    return this->grade_sign;
}

int Form::getGradeToExecute() const {
    return this->grade_ex;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() 
       << " requires grade " << form.getGradeToSign() << " to sign and grade " 
       << form.getGradeToExecute() << " to execute. "
       << "Status: " << (form.getIsSigned() ? "signed" : "not signed");
    return os;
}

void Form::beSigned(Bureaucrat const& bureaucrat) {
    if (bureaucrat.getGrade() > this->grade_sign) //son grade est trop bas
        throw Form::GradeTooLowException();
    this->is_signed = true;
}