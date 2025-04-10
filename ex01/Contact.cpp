#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    Contact MyContact;


    MyContact.setFirstName("John");
    MyContact.setLastName("Molkyboss");
    MyContact.setNickname("Molking");
    MyContact.setPhoneNumber("0797092412");
    MyContact.setDarkestSecret("je suis une fourmi");
    //print
    std::cout << "First Name: " << MyContact.getFirstName() << std::endl;
    std::cout << "Last Name: " << MyContact.getLastName() << std::endl;
    std::cout << "Nickname: " << MyContact.getNickname() << std::endl;
    std::cout << "Phone Number: " << MyContact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << MyContact.getDarkestSecret() << std::endl;
    class PhoneBook MyPhoneBook;
}
    