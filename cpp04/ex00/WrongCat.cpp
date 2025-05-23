#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    
    std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat& other)
{
    std::cout << "WrongCat copy operator called" << std::endl;
    if (this != &other)
        WrongAnimal::operator=(other);
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat desctructor called" << std::endl;
}