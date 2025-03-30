#include "Main.hpp"

bool isValidName(const std::string &name)
{
    if (name.empty())
    {
        std::cout << "Name cannot be empty!" << std::endl;
        return false;
    }
    for (char c : name)
    {
        if (!isalpha(c))
        {
            std::cout << "Name can only contain letters!" << std::endl;
            return false;
        }
    }
    return true;
}

bool isValidPhoneNumber(const std::string &phoneNumber)
{
    if (phoneNumber.empty())
    {
        std::cout << "Phone number cannot be empty!" << std::endl;
        return false;
    }
    for (char c : phoneNumber)
    {
        if (!isdigit(c))
        {
            std::cout << "Phone number can only contain digits!" << std::endl;
            return false;
        }
    }
    return true;
}

bool isValidDarkestSecret(const std::string &darkestSecret)
{
    if (darkestSecret.empty())
    {
        std::cout << "Darkest secret cannot be empty!" << std::endl;
        return false;
    }
    return true;
}

bool isValidNickname(const std::string &nickname)
{
    if (nickname.empty())
    {
        std::cout << "Nickname cannot be empty!" << std::endl;
        return false;
    }
    for (char c : nickname)
    {
        if (!isalnum(c))
        {
            std::cout << "Nickname can only contain letters and digits!" << std::endl;
            return false;
        }
    }
    return true;
}

bool check_all_valid(const std::string &firstName, const std::string &lastName, const std::string &nickname, const std::string &phoneNumber, const std::string &darkestSecret)
{
    return isValidName(firstName) && isValidName(lastName) && isValidNickname(nickname) && isValidPhoneNumber(phoneNumber) && isValidDarkestSecret(darkestSecret);
}

int main()
{
    std::cout << "PhoneBook 8 Contacts" << std::endl;
    PhoneBook phoneBook;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
    std::string command;
    while (true)
    {
        if (std::cin.eof())
        {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::cin >> command;
        if (command == "ADD")
        {
            std::cout << "Enter first name: ";
            std::cin >> firstName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;
            std::cout << "Enter nickname: ";
            std::cin >> nickname;
            std::cout << "Enter phone number: ";
            std::cin >> phoneNumber;
            std::cout << "Enter darkest secret: ";
            std::cin >> darkestSecret;
            if (!check_all_valid(firstName, lastName, nickname, phoneNumber, darkestSecret))
            {
                std::cout << "Invalid input! Please try again." << std::endl;
                continue;
            }
            phoneBook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        }
        else if (command == "SEARCH")
        {
            int maxContacts;
            if (phoneBook.index == 0)
            {
                std::cout << "No contacts available!" << std::endl;
                continue;
            }
            std::cout << std::setw(10) << "Index" << " | "
                 << std::setw(10) << "First Name" << " | "
                 << std::setw(10) << "Last Name" << " | "
                 << std::setw(10) << "Nickname" << std::endl;
            if (phoneBook.index > 8)
                maxContacts = 8;
            else
                maxContacts = phoneBook.index;
            for (int i = 0; i < maxContacts; i++)
            {
                std::cout << std::setw(10) << i << " | "
                     << std::setw(10) << (phoneBook.contacts[i].firstName.length() > 10 ? phoneBook.contacts[i].firstName.substr(0, 9) + "." : phoneBook.contacts[i].firstName) << " | "
                     << std::setw(10) << (phoneBook.contacts[i].lastName.length() > 10 ? phoneBook.contacts[i].lastName.substr(0, 9) + "." : phoneBook.contacts[i].lastName) << " | "
                     << std::setw(10) << (phoneBook.contacts[i].nickname.length() > 10 ? phoneBook.contacts[i].nickname.substr(0, 9) + "." : phoneBook.contacts[i].nickname) << std::endl;
            }
            int index;
            std::cout << "Enter index of contact to display: ";
            std::cin >> index;
            if (index < 0 || index >= phoneBook.index)
            {
                std::cout << "Invalid index!" << std::endl;
            }
            else
            {
                std::cout << "First Name: " << phoneBook.contacts[index].firstName << std::endl;
                std::cout << "Last Name: " << phoneBook.contacts[index].lastName << std::endl;
                std::cout << "Nickname: " << phoneBook.contacts[index].nickname << std::endl;
                std::cout << "Phone Number: " << phoneBook.contacts[index].phoneNumber << std::endl;
                std::cout << "Darkest Secret: " << phoneBook.contacts[index].darkestSecret << std::endl;
            }
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command!" << std::endl;
        }
    }
    return 0;
}