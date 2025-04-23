#include "Contact.hpp"
#include "PhoneBook.hpp"


int Contact::setInfo()
{
    std::string input;

    do {
        std::cout << "Enter First name:" << std:: endl;
        if (!std::getline(std::cin, input)) {
            return(0);
        }
        if (input == "EXIT")
            return(0);
        if (input.empty()) {
            std::cout << "First name cannot be empty. Please try again." << std::endl;
        }
    }
    while (input.empty()); //permet de bloquer tant que input est vide
    this->firstName = input;





    do {
        std::cout << "Enter last name" << std::endl;
        if(!std::getline(std::cin, input))
        {
            return(0);
        }
        if (input == "EXIT")
            return(0);
        if (input.empty()){
            std::cout << "last name cannot be empty. Please try again." << std::endl;
        }
    }
    while (input.empty());
    this->lastName = input;



    do {
        std::cout << "Enter nickName:" << std::endl;
        if (!std::getline(std::cin, input))
        {
            return(0);
        }
        if (input == "EXIT")
            return(0);
        if (input.empty())
        {
            std::cout << "nickname cannot be empty. Please try again." << std::endl;
        }
    }
    while (input.empty());
    this->nickName = input;



    do{
        std::cout << "Enter phone number:" << std::endl;
        if (!std::getline(std::cin, input))
        {
            return(0);
        }
        if (input == "EXIT")
            return(0);
        if (input.empty())
        {
            std::cout << "phone number cannot be empty. Please try again." << std::endl;
        }
    }
    while (input.empty());
    this->phoneNumber = input;

    do{
        std::cout << "enter darkest secret:" << std::endl;
        if (!std::getline(std::cin, input))
        {
            return(0);
        }
        if (input == "EXIT")
            return(0);
        if (input.empty())
        {
            std::cout << "darkest secret cannot be empty. Please try again." << std::endl;
        }
    }
    while (input.empty());
    this->darkestSecret = input;

    std::cout << "NEW CONTACT ADDED SUCCESSFULLY\n" << std::endl;

    return (1);
}
