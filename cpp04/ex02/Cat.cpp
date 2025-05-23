#include "Cat.hpp"

Cat::Cat() : Animal() , brain(new Brain)
{
    this->type = "Cat";
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        if (this->brain != NULL)
            delete brain;
        this->brain = new Brain(*(other.brain));
    }
    return (*this);
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat desctructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Maow!" << std::endl;
}