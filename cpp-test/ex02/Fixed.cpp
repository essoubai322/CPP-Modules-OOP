#include "Fixed.hpp"

bool Fixed::operator>(const Fixed &source) const
{
    return this->nam > source.nam;
}

bool Fixed::operator<(const Fixed &source) const
{
    return this->nam < source.nam;
}

bool Fixed::operator>=(const Fixed &source) const
{
    return this->nam >= source.nam;
}

bool Fixed::operator<=(const Fixed &source) const
{
    return this->nam <= source.nam;
}
bool Fixed::operator==(const Fixed &source) const
{
    return this->nam == source.nam;
}
bool Fixed::operator!=(const Fixed &source) const
{
    return this->nam != source.nam;
}
float Fixed::operator+(const Fixed &source) const
{
    return this->toFloat() + source.toFloat();
}
float Fixed::operator-(const Fixed &source) const
{
    return this->toFloat() - source.toFloat();
}
float Fixed::operator*(const Fixed &source) const
{
    return this->toFloat() * source.toFloat();
}
float Fixed::operator/(const Fixed &source) const
{
    return this->toFloat() / source.toFloat();
}

int Fixed::getRawBits(void) const
{
    return (nam);
}
void Fixed::setRawBits( int const raw )
{
    this->nam = raw;
}

Fixed::Fixed() : nam(0) {};
Fixed::~Fixed(){};

Fixed &Fixed::operator=(const Fixed &test)
{
    if (this != &test)
        this->nam = test.nam;
    return (*this);
}

Fixed::Fixed(const Fixed &copy) 
{
    *this = copy;
}

Fixed::Fixed(const float a) : nam(roundf(a * (1 << 8)))
{
}

Fixed::Fixed(const int a) : nam(a * (1 << 8)) 
{
}

int Fixed::toInt(void) const
{
    return (nam / (1 << 8));
}

float Fixed::toFloat(void) const
{
    return ((float)(nam) / (1 << 8));
}

Fixed &Fixed::operator++()
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->setRawBits(this->getRawBits() + 1);
    return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) 
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) 
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{
    return (a > b) ? a : b;
}
