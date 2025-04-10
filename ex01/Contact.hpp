 #ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        Contact() 
            : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

        void setFirstName(std::string newFirstName) {
            firstName = newFirstName;
        }
        void setLastName(std::string newLastName) {
            lastName = newLastName;
        }
        void setNickname(std::string newNickname) {
            nickname = newNickname;
        }
        void setPhoneNumber(std::string newPhoneNumber) {
            phoneNumber = newPhoneNumber;
        }
        void setDarkestSecret(std::string newDarkestSecret) {
            darkestSecret = newDarkestSecret;
        }
        // getters pour pouvoir acceder aux attributs privés
        std::string getFirstName() {
            return (firstName);
        }
        std::string getLastName() {
            return (lastName);
        }
        std::string getNickname() {
            return (nickname);
        }
        std::string getPhoneNumber() {
            return (phoneNumber);
        }
        std::string getDarkestSecret() {
            return (darkestSecret);
        }
};
#endif