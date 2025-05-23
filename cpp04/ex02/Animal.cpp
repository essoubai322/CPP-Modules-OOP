#include "Animal.hpp"

void Animal::makeSound() const
{
    std::cout << "Animal has no sound" << std::endl;
}

std::string Animal::getType() const
{
    return (type);
}

Animal::Animal() : type("no type")
{
    std::cout << "Constructor Animal Default!" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    *this = copy;
    std::cout << "Copy Constructor Animal" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "copy assignment constructor Animal" << std::endl;
    if (this != &copy)
    {
        this->type = copy.type;
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Destructor Animal!" << std::endl;
}
