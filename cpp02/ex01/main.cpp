#include <iostream>
#include <cstring>
#include <cmath>

class Fixed 
{
    private :
        int value;
        static const int fractional; 
    public :
        Fixed();
        Fixed(int n);
        Fixed(float n);
        Fixed &operator=(const Fixed &copy);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed( const Fixed &copy );
};

const int Fixed::fractional = 8;

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &copy ) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=( const Fixed &copy ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy) {
        this->value = copy.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    return this->value;
}

void Fixed::setRawBits( int const raw ) {
    this->value = raw;
}

Fixed::Fixed(int n) : value(n * (pow(2, fractional)))
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float n) : value(roundf(n * (pow(2, fractional)))) 
{
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return (float)value / 256;
}   

int Fixed::toInt(void) const
{
    return value / 256;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

int main( void ) 
{
    // Fixed a;
    // Fixed const b( 10 );
    Fixed const c( 42.42f );
    // Fixed const d( b );
    // a = Fixed( 1234.4321f );
    // std::cout << "a is " << a << std::endl;
    // std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    // std::cout << "d is " << d << std::endl;
    // std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    // std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    // std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    // std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    // return 0;
}