#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{

    class PhoneBook MyPhoneBook;
    std::string input;
    int exit_flag = 0;

    while (1)
    {

        std::cout << "enter cmd: " << std::endl;
        if (!std::getline(std::cin, input))
        {
            std::cout << "EXITING PHONEBOOK..." << std::endl;
            break;
        }


        if (input.empty())
        {
            std::cout << "error empty string input" << std::endl;
        }




       else if (input == "ADD")
        {
            std::cout << "ADD MODE" << std::endl;
            if(!MyPhoneBook.addContact())
            {
                std::cout << "EXITING PHONEBOOK..." << std::endl;
                break;
            }
        }


        else if (input == "SEARCH")
        {
            std::cout << "SEARCH MODE" << std::endl;
            MyPhoneBook.displayContacts(-1);
            MyPhoneBook.searchContacts(0);
            // MyPhoneBook.searchContact();
        }


        else if (input == "EXIT" || exit_flag == 2)
        {
            std::cout << "EXITING PHONEBOOK..." << std::endl;
            break;
        }
        else
        {
            std::cout << "invalid command" << std::endl;
        }
    }
    return (0);
    
}