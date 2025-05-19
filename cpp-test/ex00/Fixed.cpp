#include "Fixed.hpp"

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (nam);
}
void Fixed::setRawBits( int const raw )
{
    this->nam = raw;
}

Fixed::Fixed() : nam(0) {std::cout << "Default constructor called" << std::endl;};
Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;};

Fixed &Fixed::operator=(Fixed &test)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &test)
        this->nam = test.nam;
    return (*this);
}

Fixed::Fixed(Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}