#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void){
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
}