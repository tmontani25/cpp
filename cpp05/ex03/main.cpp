#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"



int main (void)
{

    //presidential tester
    std::cout<<"PRESIDENTIAL TESTER\n";
    std::cout<<"\ntest presidential OK to sign and execute\n"<< std::endl;

    Bureaucrat bob("Bob", 1);  
    PresidentialPardonForm presidential_test("ben laden");

    bob.signForm(presidential_test);
    std::cout << presidential_test.getIsSigned()<<std::endl; // signe ou non
    bob.executeForm(presidential_test);

    std::cout<<"\n\ntest presidential form grade too low to sign and execute:\n"<< std::endl;

    Bureaucrat alice("Alice", 150); 
    PresidentialPardonForm test("pablo escobar");
    alice.signForm(test);
    std::cout<<"est ce que le fichier a ete signe 1 oui 0 non:\n";
    std::cout << test.getIsSigned()<<std::endl;
    alice.executeForm(test);

    std::cout<<"\nAlice essaye d'executer un form signe mais elle n'as pas le grade suffisant:\n"<< std::endl;
    alice.executeForm(presidential_test);

    //Shrubbery tests
    std::cout<< "\nSHRUBBERY TESTER\n";

    try {
        ShrubberyCreationForm form("home");  // Juste crée le formulaire, pas de fichier créé
        
        Bureaucrat boss("Boss", 100);        // Grade suffisant pour signer et exécuter
        
        boss.signForm(form);                 // Le formulaire est signé
        boss.executeForm(form);              // C'est ICI que le fichier home_shrubbery est créé
        
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    //robotomy tests
    std::cout << "\nROBOTOMY TESTER\n";
    
    std::cout << "\nTest avec grade suffisant (plusieurs essais pour voir le random):\n";
    try {
        Bureaucrat chief("Chief", 40);  // Grade 40 < 45 requis pour executer
        RobotomyRequestForm robot("Marvin");
        
        chief.signForm(robot);
        // On teste plusieurs fois pour voir les différents résultats aléatoires
        for (int i = 0; i < 4; i++) {
            std::cout << "\nEssai " << i + 1 << ":\n";
            chief.executeForm(robot);
        }
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nTest avec grade insuffisant:\n";
    try {
        Bureaucrat intern("Intern", 150);
        RobotomyRequestForm robot2("Bender");
        
        intern.signForm(robot2);        // Ne pourra pas signer (grade 150 > 72)
        intern.executeForm(robot2);     // Ne pourra pas exécuter (non signé + grade 150 > 45)
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout<< "\nROBOTOMY TESTER\n";
    RobotomyRequestForm test2("michel");

    Bureaucrat jean_pascal("jean pascal", 10); 
    Bureaucrat tony_parker("tony parker", 150);

    jean_pascal.signForm(test2);
    std::cout<< "c'est signe ou non: "<< test2.getIsSigned()<<std::endl;
    std::cout<<"allez jp execute nous ca\n";
    jean_pascal.executeForm(test2);
 

        std::cout<< "\nINTERN TESTER\n";

    Intern  someRandomIntern;
    AForm*   rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    jean_pascal.signForm(*rrf);
    std::cout<< "signe ou non "<< rrf->getIsSigned()<<std::endl;
    jean_pascal.executeForm(*rrf);
    
    // nettoyage du formulaire créé par l'Intern
    delete rrf;

    // Test pour formulaire inconnu (doit lancer une exception)
    std::cout << "\nTest Intern makeForm inconnu:\n";
    try {
        AForm* bad = someRandomIntern.makeForm("unknown form", "Nobody");
        if (bad) {
            jean_pascal.signForm(*bad);
            jean_pascal.executeForm(*bad);
            delete bad;
        }
    } catch (std::exception &e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    return 0;
}