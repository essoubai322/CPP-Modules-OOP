#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        if (this->brain != NULL)
            delete this->brain;
        this->brain = new Brain((*other.brain));
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog desctructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "3AAWW 3AWWW!" << std::endl;
}
