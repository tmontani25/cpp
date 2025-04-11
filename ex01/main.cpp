#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{

    class PhoneBook MyPhoneBook;
    std::string input;

    std::cout << "enter cmd: " << std::endl;
    std::getline(std::cin, input);

    if (input.empty()){
        std::cout << "error empty string input" << std::endl;
        return (1);
    }
    if (input == "ADD")
    {
        std::cout << "ADD a contact" << std::endl;
        MyPhoneBook.addContact();

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
    
}