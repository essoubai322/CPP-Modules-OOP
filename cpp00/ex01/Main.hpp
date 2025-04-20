#ifndef MAIN_HPP
# define MAIN_HPP

#include <cstring>
#include <iostream>
#include <iomanip>

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
        void setFirstName(std::string name) { firstName = name; }
        void setLastName(std::string name) { lastName = name; }
        void setNickname(std::string name) { nickname = name; }
        void setPhoneNumber(std::string number) { phoneNumber = number; }
        void setDarkestSecret(std::string secret) { darkestSecret = secret; }
        std::string getFirstName() const { return firstName; }
        std::string getLastName() const { return lastName; }
        std::string getNickname() const { return nickname; }
        std::string getPhoneNumber() const { return phoneNumber; }
        std::string getDarkestSecret() const { return darkestSecret; }
};

class PhoneBook
{
public:
    Contact contacts[8];
    int index;

    PhoneBook() : index(0) {}

    void addContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
    {
        if (!contacts[index % 8].checkFirstName(firstName) || 
            !contacts[index % 8].checkLastName(lastName) || 
            !contacts[index % 8].checkNickname(nickname) || 
            !contacts[index % 8].checkPhoneNumber(phoneNumber) || 
            !contacts[index % 8].checkDarkestSecret(darkestSecret))
        {
            std::cerr << "Invalid input!" << std::endl;
            return;
        }
        contacts[index % 8].setFirstName(firstName);
        contacts[index % 8].setLastName(lastName);
        contacts[index % 8].setNickname(nickname);
        contacts[index % 8].setPhoneNumber(phoneNumber);
        contacts[index % 8].setDarkestSecret(darkestSecret);
        index++;
    }
};
#endif
