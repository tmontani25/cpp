#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp" // Include the Contact class header
#include <iostream>
#include <string>

class PhoneBook {
    private:
        Contact contacts[8];
        int contactCount; // pour savoir combien de contact dans tableau
    public:
    PhoneBook() { std:: cout << "PhoneBook class created default constructor called" << std::endl;}




    // methodes
    void addContact(int index);
    void displayContact(int index);

};
#endif