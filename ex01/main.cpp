#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{

    class PhoneBook MyPhoneBook;
    std::string input;

    while (1)
    {

        std::cout << "enter cmd: " << std::endl;
        std::getline(std::cin, input);


        if (input.empty())
        {
            std::cout << "error empty string input" << std::endl;
        }
       else if (input == "ADD")
        {
            std::cout << "ADD MODE" << std::endl;
            MyPhoneBook.addContact();
        }
        else if (input == "SEARCH")
        {
            std::cout << "SEARCH MODE" << std::endl;
            MyPhoneBook.displayContacts();
            // MyPhoneBook.searchContact();
        }
        else if (input == "EXIT")
        {
            std::cout << "EXITING PHONEBOOK..." << std::endl;
            break;
        }
        else
        {
            std::cout << "invalid command" << std::endl;
        }
    }

    // Contact MyContact;

    // MyContact.setFirstName("John");
    // MyContact.setLastName("Molkyboss");
    // MyContact.setNickname("Molking");
    // MyContact.setPhoneNumber("0797092412");
    // MyContact.setDarkestSecret("je suis une fourmi");
    // //print
    // std::cout << "First Name: " << MyContact.getFirstName() << std::endl;
    // std::cout << "Last Name: " << MyContact.getLastName() << std::endl;
    // std::cout << "Nickname: " << MyContact.getNickname() << std::endl;
    // std::cout << "Phone Number: " << MyContact.getPhoneNumber() << std::endl;
    // std::cout << "Darkest Secret: " << MyContact.getDarkestSecret() << std::endl;
    return (0);
    
}