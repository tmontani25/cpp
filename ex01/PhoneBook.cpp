#include "PhoneBook.hpp"
#include "Contact.hpp"

// ici je cree les methodes pour la class phonebook

void PhoneBook::addContact()
{
    // si moins de 8 contact ajoute a la suite sinon remplace le plus ancien

    if (contactCount < 8)
    {
        contacts[contactCount].setInfo();
        contactCount++;
    }
}
void PhoneBook::displayContact(int index)
{
    (void)index;
}