 #ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        Contact() 
            : firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("") {}

        int setInfo();

        // getters pour pouvoir acceder aux attributs privés
        std::string getFirstName() {
            return (firstName);
        }
        std::string getLastName() {
            return (lastName);
        }
        std::string getNickname() {
            return (nickName);
        }
        std::string getPhoneNumber() {
            return (phoneNumber);
        }
        std::string getDarkestSecret() {
            return (darkestSecret);
        }
};
#endif