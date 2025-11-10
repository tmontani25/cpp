#include "ShrubberyCreationForm.hpp"

//constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
: AForm("Shrubbery Creation Form", 145, 137), _target(target){}

//copie
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), _target(other._target){}

//destructeur
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

// ******************** methodes ******************************//

void ShrubberyCreationForm::writeTreeToFile() const {
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile.is_open())
        throw std::runtime_error("Cannot create shrubbery file");
    
    outfile << "      /\\\n";
    outfile << "     /\\*\\\n";
    outfile << "    /\\O\\*\\\n";
    outfile << "   /*/\\/\\/\\\n";
    outfile << "  /\\O\\/\\*\\/\\\n";
    outfile << " /\\*\\/\\*\\/\\/\\\n";
    outfile << "/\\O\\/\\/*/\\/O/\\\n";
    outfile << "      ||\n";
    outfile << "      ||\n";
    outfile << "      ||\n";
    
    outfile.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    executeCheck(executor); // Vérifie si le form est signé et si le grade est suffisant
    
    writeTreeToFile();
}





