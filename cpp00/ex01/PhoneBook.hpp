#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp" // Include the Contact class header
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class PhoneBook {
    private:
        Contact contacts[8];
        int contactCount; // pour savoir combien de contact dans tableau
    public:
    PhoneBook() { std:: cout << "PhoneBook class created default constructor called" << std::endl;
    contactCount = 0;
    }



    // methodes
    int addContact(void);
    int displayContacts(int index);
    int searchContacts(int index);

};
#endif