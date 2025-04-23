#include "Contact.hpp"
#include "Phonebook.hpp"
#include <limits>

int main()
{
    PhoneBook phoneBook;
    std::string command; 
    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (std::cin.eof())
                break;
        if (command == "ADD")
        {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
            std::cout << "Enter first name: ";
            std::getline(std::cin, firstName);
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            std::cout << "Enter nickname: ";
            std::getline(std::cin, nickname);
            std::cout << "Enter phone number: ";
            std::getline(std::cin, phoneNumber);
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, darkestSecret);
            if (std::cin.eof())
                break;
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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.eof())
                break;
            else if (std::cin.fail())
            {
                std::cout << "Invalid input! You must enter a number." << std::endl;
                break;
            }

            if (index >= 0 && index < 8 && !phoneBook.contacts[index].getFirstName().empty())
            {
                std::cout << "First Name: " << phoneBook.contacts[index].getFirstName() << std::endl;
                std::cout << "Last Name: " << phoneBook.contacts[index].getLastName() << std::endl;
                std::cout << "Nickname: " << phoneBook.contacts[index].getNickname() << std::endl;
                std::cout << "Phone Number: " << phoneBook.contacts[index].getPhoneNumber() << std::endl;
                std::cout << "Darkest Secret: " << phoneBook.contacts[index].getDarkestSecret() << std::endl;
            }
            else
                std::cout << "Invalid index." << std::endl;
        }
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command." << std::endl;
    }
    return 0;
}