#include "Contact.hpp"
#include "PhoneBook.hpp"


void Contact::setInfo()
{
    std::string input;

    do {
        std::cout << "Enter First name:" << std:: endl;
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "First name cannot be empty. Please try again." << std::endl;
        }
    }
    while (input.empty() || input == "EXIT"); //permet de bloquer tant que input est vide
    this->firstName = input;

    do {
        std::cout << "Enter last name" << std::endl;
        std::getline(std::cin, input);
        if (input.empty()){
            std::cout << "last name cannot be empty. Please try again." << std::endl;
        }

    }
    while (input.empty() || input == "EXIT");
    this->lastName = input;

    std::cout << "Enter nickName:" << std::endl;
    std::getline(std::cin, input);
    if (input.empty())
        return;
    this->nickName = input;


    std::cout << "Enter phone number:" << std::endl;
    std::getline(std::cin, input);
    if (input.empty())
        return;
    this->phoneNumber = input;


    std::cout << "Enter darkest secret:" << std::endl;
    std::getline(std::cin, input);
    if (input.empty())
        return;
    this->darkestSecret = input;

    std::cout << "NEW CONTACT ADDED SUCCESSFULLY\n" << std::endl;

}