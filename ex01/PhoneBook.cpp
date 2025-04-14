#include "PhoneBook.hpp"
#include "Contact.hpp"

// ici je cree les methodes pour la class phonebook

void PhoneBook::addContact()
{
    int index;
    
    index = contactCount % 8;

    if (contactCount < 8)
    {
        contacts[contactCount].setInfo();
        contactCount++;
    }
    else
    {
        contacts[index].setInfo();
        contactCount = 8;
    }
    
}
void PhoneBook::displayContacts(void)
{

    if (contactCount == 0)
    {
        std::cout << "NO CONTACTS..." << std::endl;
        return ;
    }

    std::cout << "  Index | First Name | Last Name  | Nickname" << std::endl;

    for (int i = 0; i < contactCount; ++i) {
        std::cout << std::setw(6) << std::right << i << " | ";  // Index
        std::cout << std::setw(10) << std::right << contacts[i].getFirstName() << " | ";  // First name
        std::cout << std::setw(10) << std::right << contacts[i].getLastName() << " | ";  // Last name
        std::cout << std::setw(10) << std::right << contacts[i].getNickname() << std::endl;  // Nickname
    }
}
