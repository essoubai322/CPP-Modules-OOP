#include "Fixed.hpp"

int Fixed::getRawBits(void) const
{
    return (nam);
}
void Fixed::setRawBits( int const raw )
{
    this->nam = raw;
}

Fixed::Fixed() : nam(0) {std::cout << "Default constructor called" << std::endl;};
Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;};

Fixed &Fixed::operator=(const Fixed &test)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &test)
        this->nam = test.nam;
    return (*this);
}

Fixed::Fixed(const Fixed &copy) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(const float a) : nam(roundf(a * pow(2,frac)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int a) : nam(a * pow(2,frac)) 
{
    std::cout << "Int constructor called" << std::endl;
}

int Fixed::toInt(void) const
{
    return (nam / pow(2,frac));
}

float Fixed::toFloat(void) const
{
    return (nam / pow(2, frac));
}