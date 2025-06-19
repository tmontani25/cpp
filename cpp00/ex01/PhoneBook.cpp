#include "PhoneBook.hpp"
#include "Contact.hpp"

// ici je cree les methodes pour la class phonebook

int PhoneBook::addContact()
{
    int index;
    
    index = contactCount % 8;

    if (contactCount < 8)
    {
        if(!contacts[contactCount].setInfo())
        {
            return (0);
        }
        contactCount++;
    }
    else if (contactCount == 8)
    {
        std::cout << "PhoneBook is full, overwriting contact at index 7" << index << std::endl;
        for (int i = 7; i > 0; --i)
        {
            contacts[i] = contacts[i - 1];
        }
        if(!contacts[0].setInfo())
        {
            return (0);
        }
    }
    else
    {
        if(!contacts[index].setInfo())
        {
            return (0);
        }
        contactCount = 8;
    }
    return (1);
    
}
int PhoneBook::displayContacts(int index)
{
   std::string input;

    if (contactCount == 0)
    {
        std::cout << "NO CONTACTS..." << std::endl;
        return (-1);
    }

    if(index == -1)
    {
        std::cout << "  Index | First Name | Last Name  | Nickname  |" << std::endl;

        for (int i = 0; i < contactCount; ++i) {
            std::cout << std::setw(6) << std::right << i << " | ";  // Index
            std::cout << std::setw(10) << std::right << contacts[i].getFirstName() << " | ";  // First name
            std::cout << std::setw(10) << std::right << contacts[i].getLastName() << " | ";  // Last name
            std::cout << std::setw(10) << std::right << contacts[i].getNickname() << " | "; // Nickname
            std::cout << std::setw(10) << std::right << contacts[i].getPhoneNumber() << " | ";  // Phone number
            std::cout << std::setw(10) << std::right << contacts[i].getDarkestSecret() << std::endl;
        }
    }
    return (1);
}

int PhoneBook::searchContacts(int index)
{

    
    std::string input;

    std::cout << "Enter the index of the contact you want to search for: ";
    do
    {
        if(!std::getline(std::cin, input))
        {
            return (0);
        }
        if (input.empty())
        {
            std::cout << "error empty string input" << std::endl;
        }
        if (input == "EXIT")
        {
            return (0);
        }
        index = atoi(input.c_str());
        if (index < 0 || index >= contactCount)
        {
            std::cout << "Invalid index. Please enter a valid index." << std::endl;
        }
    } while (index < 0 || index >= contactCount || input.empty());
    std::cout << "Contact found:" << std::endl;
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
    return (1);
    
}

