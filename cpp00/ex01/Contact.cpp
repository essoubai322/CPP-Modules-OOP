#include "Contact.hpp"

void Contact::setFirstName(std::string name)
{
    firstName = name;
}

void Contact::setLastName(std::string name)
{
    lastName = name;
}

void Contact::setNickname(std::string name)
{
    nickname = name;
}

void Contact::setPhoneNumber(std::string number)
{
    phoneNumber = number;
}

void Contact::setDarkestSecret(std::string secret)
{
    darkestSecret = secret;
}

std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickname() const
{
    return nickname;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}

bool Contact::checkFirstName(std::string name)
{
    if (name.empty())
    {
        std::cout << "First name cannot be empty." << std::endl;
        return false;
    }
    for (std::string::size_type i = 0; i < name.length(); ++i)
    {
        if (!isalpha(name[i]))
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
    for (std::string::size_type i = 0; i < name.length(); ++i)
    {
        if (!isalpha(name[i]))
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
    for (std::string::size_type i = 0; i < name.length(); ++i)
    {
        if (!isalpha(name[i]))
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
    for (std::string::size_type i = 0; i < number.length(); ++i)
    {
        if (!isdigit(number[i]))
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
