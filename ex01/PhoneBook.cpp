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
    std::cout << "Enter index of contact to search: " << std::endl;
    do {
        if (!std::getline(std::cin, input)) {
            std::cout << "Error: ctrl + D detected. Exiting search mode." << std::endl;
            return (0);
        }

        if (input.empty()) {
            std::cout << "Error: empty input. Please enter a valid index." << std::endl;
            continue; // Redemande une entrée
        }

        try {
            index = std::stoi(input); // Convertit la chaîne en entier
            if (index < 0 || index >= contactCount) {
                std::cout << "Invalid index. Please try again." << std::endl;
            } else {
                // Affiche les informations du contact
                std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
                std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
                std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
                std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
                std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
                break; // Sort de la boucle après un index valide
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Error: invalid input. Please enter a numeric index." << std::endl;
        } catch (const std::out_of_range&) {
            std::cout << "Error: number out of range. Please enter a valid index." << std::endl;
        }
    } while (true);

    return (1);
}

