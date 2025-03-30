#ifndef MAIN_HPP
# define MAIN_HPP

#include <cstring>
#include <iostream>
#include <iomanip>

class Contact
{
public:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    Contact() {}
    void setFirstName(std::string name) { firstName = name; }
    void setLastName(std::string name) { lastName = name; }
    void setNickname(std::string name) { nickname = name; }
    void setPhoneNumber(std::string number) { phoneNumber = number; }
    void setDarkestSecret(std::string secret) { darkestSecret = secret; }
};

class PhoneBook
{
public:
    Contact contacts[8];
    int index;

    PhoneBook() : index(0) {}

    void addContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
    {
        contacts[index % 8].setFirstName(firstName);
        contacts[index % 8].setLastName(lastName);
        contacts[index % 8].setNickname(nickname);
        contacts[index % 8].setPhoneNumber(phoneNumber);
        contacts[index % 8].setDarkestSecret(darkestSecret);
        index++;
    }
};
#endif
