#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <cstring>
#include <iostream>
#include <iomanip>
#include <sstream>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        Contact() {}
        bool checkFirstName(std::string name);
        bool checkLastName(std::string name);
        bool checkNickname(std::string name);
        bool checkPhoneNumber(std::string number);
        bool checkDarkestSecret(std::string secret);
        void setFirstName(std::string name);
        void setLastName(std::string name);
        void setNickname(std::string name);
        void setPhoneNumber(std::string number);
        void setDarkestSecret(std::string secret);
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
};

#endif