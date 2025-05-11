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

        bool operator>(const Fixed &source) const;
        bool operator<(const Fixed &source) const;
        bool operator>=(const Fixed &source) const;
        bool operator<=(const Fixed &source) const;
        bool operator==(const Fixed &source) const;
        bool operator!=(const Fixed &source) const;
        float operator+(const Fixed &source) const;
        float operator-(const Fixed &source) const;
        float operator*(const Fixed &source) const;
        float operator/(const Fixed &source) const;
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

const int Fixed::fractional = 8;

Fixed::Fixed() : value(0) {
}

Fixed::Fixed( const Fixed &copy ) 
{
    *this = copy;
}

Fixed &Fixed::operator=( const Fixed &copy ) {
    if (this != &copy) {
        this->value = copy.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits( void ) const {
    return this->value;
}

void Fixed::setRawBits( int const raw ) {
    this->value = raw;
}

Fixed::Fixed(int n) : value(n << fractional) 
{
}

Fixed::Fixed(float n) : value(roundf(n * 256)) 
{
}

float Fixed::toFloat(void) const
{
    return (float)value / 256;
}   

int Fixed::toInt(void) const
{
    return value >> fractional;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

/// 

bool Fixed::operator>(const Fixed &source) const
{
    return this->value > source.value;
}

bool Fixed::operator<(const Fixed &source) const
{
    return this->value < source.value;
}

bool Fixed::operator>=(const Fixed &source) const
{
    return this->value >= source.value;
}

bool Fixed::operator<=(const Fixed &source) const
{
    return this->value <= source.value;
}
bool Fixed::operator==(const Fixed &source) const
{
    return this->value == source.value;
}
bool Fixed::operator!=(const Fixed &source) const
{
    return this->value != source.value;
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

Fixed &Fixed::operator++()
{
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->value++;
    return temp;
}

Fixed &Fixed::operator--()
{
    this->value--;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->value--;
    return temp;
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



int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}