#include "WrongAnimal.hpp"

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal has no sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}

WrongAnimal::WrongAnimal() : type("no type")
{
    std::cout << "Constructor WrongAnimal Default!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    *this = copy;
    std::cout << "Copy Constructor WrongAnimal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout << "copy assignment constructor WrongAnimal" << std::endl;
    if (this != &copy)
    {
        this->type = copy.type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor Animal!" << std::endl;
}