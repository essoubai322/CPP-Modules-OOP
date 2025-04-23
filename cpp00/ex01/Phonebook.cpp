#include "Phonebook.hpp"

void PhoneBook::addContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
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
