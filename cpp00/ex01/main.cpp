#include "Main.hpp"

bool Contact::checkFirstName(std::string name)
{
    if (name.empty())
    {
        std::cout << "First name cannot be empty." << std::endl;
        return false;
    }
    for (char c : name)
    {
        if (!isalpha(c))
        {
            std::cout << "First name can only contain alphabetic characters." << std::endl;
            return false;
        }
    }
    return true;
}

bool Contact::checkLastName(std::string name)
{
    if (name.empty())
    {
        std::cout << "Last name cannot be empty." << std::endl;
        return false;
    }
    for (char c : name)
    {
        if (!isalpha(c))
        {
            std::cout << "Last name can only contain alphabetic characters." << std::endl;
            return false;
        }
    }
    return true;
}

bool Contact::checkNickname(std::string name)
{
    if (name.empty())
    {
        std::cout << "Nickname cannot be empty." << std::endl;
        return false;
    }
    for (char c : name)
    {
        if (!isalpha(c))
        {
            std::cout << "Nickname can only contain alphabetic characters." << std::endl;
            return false;
        }
    }
    return true;
}

bool Contact::checkPhoneNumber(std::string number)
{
    if (number.empty())
    {
        std::cout << "Phone number cannot be empty." << std::endl;
        return false;
    }
    for (char c : number)
    {
        if (!isdigit(c))
        {
            std::cout << "Phone number can only contain digits." << std::endl;
            return false;
        }
    }
    return true;
}

bool Contact::checkDarkestSecret(std::string secret)
{
    if (secret.empty())
    {
        std::cout << "Darkest secret cannot be empty." << std::endl;
        return false;
    }
    darkestSecret = secret;
    return true;
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::cin >> command;

        if (command == "ADD")
        {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
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
            phoneBook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        }
        else if (command == "SEARCH")
        {
            std::cout << std::setw(10) << "Index" << "|" 
                      << std::setw(10) << "First Name" << "|"
                      << std::setw(10) << "Last Name" << "|"
                      << std::setw(10) << "Nickname" << "|" << std::endl;

            for (int i = 0; i < 4; ++i)
            {
                if (phoneBook.contacts[i].getFirstName().empty())
                    continue;
                std::cout << std::setw(10) << i << "|"
                          << std::setw(10) << phoneBook.contacts[i].getFirstName() << "|"
                          << std::setw(10) << phoneBook.contacts[i].getLastName() << "|"
                          << std::setw(10) << phoneBook.contacts[i].getNickname() << "|" 
                          << std::endl;
            }

            int index;
            std::cout << "Enter the index of the contact to display: ";
            std::cin >> index;

            if (index >= 0 && index < 8 && !phoneBook.contacts[index].getFirstName().empty())
            {
                std::cout << "First Name: " << phoneBook.contacts[index].getFirstName() << std::endl;
                std::cout << "Last Name: " << phoneBook.contacts[index].getLastName() << std::endl;
                std::cout << "Nickname: " << phoneBook.contacts[index].getNickname() << std::endl;
                std::cout << "Phone Number: " << phoneBook.contacts[index].getPhoneNumber() << std::endl;
                std::cout << "Darkest Secret: " << phoneBook.contacts[index].getDarkestSecret() << std::endl;
            }
            else
            {
                std::cout << "Invalid index." << std::endl;
            }
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command." << std::endl;
        }
    }
    return 0;
}