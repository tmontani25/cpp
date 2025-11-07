#include "AForm.hpp"
#include "Bureaucrat.hpp"
//*********************  forme canonique classique ******************* */
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), grade_sign(gradeToSign), grade_ex(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned),
      grade_sign(other.grade_sign), grade_ex(other.grade_ex)
{
}

AForm::~AForm()
{
}
// ********************** methodes *********************
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->grade_sign)
        throw AForm::GradeTooLowException();
    this->isSigned = true;
}

void AForm::executeCheck(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw AForm::NotSignedException(); //check si c'est signed
    if (executor.getGrade() > this->grade_ex) //check le grade
        throw AForm::GradeTooLowException();
}

// ******************* Getters **************************
const std::string& AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getGradeToSign() const
{
    return this->grade_sign;
}

int AForm::getGradeToExecute() const
{
    return this->grade_ex;
}

//******************* */ Exceptions ***************************
const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

//implementationde NotSignedException
const char *AForm::NotSignedException :: what() const throw()
{
    return "Form not signed";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "Form is not signed";
}

// ****************** Surcharge d'opérateur *********************
std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form " << form.getName() 
       << " requires grade " << form.getGradeToSign() << " to sign and grade "
       << form.getGradeToExecute() << " to execute. "
       << "Status: " << (form.getIsSigned() ? "signed" : "not signed");
    return os;
}