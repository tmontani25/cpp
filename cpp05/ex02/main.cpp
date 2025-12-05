#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"



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

}
    
    
/*int main (void){
    // Création sur la pile (stack)
    Bureaucrat bob("Bob", 1);          // Crée un Bureaucrat nommé "Bob" de grade 1
    Bureaucrat alice("Alice", 150);     // Crée un Bureaucrat nommé "Alice" de grade 150

    // Création sur le tas (heap) avec new
    Bureaucrat* pablo = new Bureaucrat("Pablo", 42);

    //test de surcharge operateur<< 
    std::cout << alice << std::endl;
    std::cout << bob << std::endl;
    std::cout << *pablo << std::endl;
    std::cout << "\n\n";

    //test Form simple
    std::cout << "simple test form signing\n\n";
    Form test("test", 5, 5);
    std::cout <<test<< std::endl;
    Bureaucrat notaire("paul", 1);
    notaire.signForm(test);
    std::cout << test << std::endl;

    Bureaucrat boss("boss", 1);         // Très haut grade
    Bureaucrat employe("employe", 100); // Grade moyen
    Form secret("Secret_files", 2, 2);  // Requiert un très haut grade
    Form chill("chill_file", 100, 100); // Requiert un grade moyen

    // Affichage initial
    std::cout << "\nÉtat initial :" << std::endl;
    std::cout << boss << std::endl;
    std::cout << employe << std::endl;
    std::cout << secret << std::endl;
    std::cout << chill << std::endl;

    // Test 1: Boss tente de signer le document secret (devrait réussir)
    std::cout << "\nTest 1 - Boss tente de signer le document secret:" << std::endl;
    boss.signForm(secret);

    // Test 2: Employé tente de signer le document secret (devrait échouer)
    std::cout << "\nTest 2 - Employé tente de signer le document secret:" << std::endl;
    employe.signForm(secret);

    // Test 3: Employé tente de signer le document chill (devrait réussir)
    std::cout << "\nTest 3 - Employé tente de signer le document chill:" << std::endl;
    employe.signForm(chill);

    // Test 4: Boss tente de signer le document chill (devrait réussir)
    std::cout << "\nTest 4 - Boss tente de signer le document chill:" << std::endl;
    boss.signForm(chill);

    // Affichage final des états des documents
    std::cout << "\nÉtat final des documents:" << std::endl;
    std::cout << secret << std::endl;
    std::cout << chill << std::endl;






//     std::cout << "test grade invalide\n\n";
//     try {
//         // Test avec un grade invalide
//         Bureaucrat trop_haut("high", 151);  // Va lancer une exception GradeTooLowException
//     }
//     catch (const std::exception& e) {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
//     try {
//         // Test avec un grade 
//         Bureaucrat trop_bas("low", 0);  // Va lancer une exception GradeTooHighException
//     }
//     catch (const std::exception& e) {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
//     std::cout << "\n\n";
    
//     //increment decrement
//     std::cout << "test increment decrement\n\n";
//     Bureaucrat proton("Proton", 2);
//     Bureaucrat noe("Noe", 149);

    
//     std::cout << proton << std::endl;
//     proton.incrementGrade();
//     std::cout << proton << std::endl;

//     try{
//             proton.incrementGrade(); //trop haut = 0
//     }
//     catch (const std::exception& e) {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }
    
 
//     std::cout << noe << std::endl;
//     noe.decrementGrade();
//     std::cout << noe << std::endl;
//     try{

//         noe.decrementGrade();
//     }
//         catch (const std::exception& e) {
//         std::cout << "Exception: " << e.what() << std::endl;
//     }





//     std::cout<<"\n\n\n";
//     std::cout<<"test increment decrement en boucle\n\n";
//     try {
//     std::cout << "Test incrémentation avec " << noe << std::endl;
//     while (true) {
//         noe.incrementGrade();
//         std::cout << noe << std::endl;
//     }
// }
// catch (const std::exception& e) {
//     std::cout << "Exception attrapée : " << e.what() << std::endl;
// }

// try {
//     std::cout << "\nTest décrémentation avec " << proton << std::endl;
//     while (true) {
//         proton.decrementGrade();
//         std::cout << proton << std::endl;
//     }
// }
// catch (const std::exception& e) {
//     std::cout << "Exception attrapée : " << e.what() << std::endl;
// }

    delete pablo;

    return 0;
}*/
