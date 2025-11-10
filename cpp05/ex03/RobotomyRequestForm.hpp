#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    const std::string _target;  // Même logique que Presidential
    static bool _seeded;  // Pour s'assurer qu'on initialise le random une seule fois
    RobotomyRequestForm& operator=(RobotomyRequestForm const &src);

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(RobotomyRequestForm const &src);
    virtual ~RobotomyRequestForm();

  

    virtual void execute(Bureaucrat const &executor) const;
};

#endif