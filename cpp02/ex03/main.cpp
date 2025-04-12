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

class triangle
{
    private:
        Fixed x;
        Fixed y;
    public :
        triangle();
        triangle(Fixed x, Fixed y);
        triangle(const triangle &copy);
        triangle &operator=(const triangle &copy);
        ~triangle();
        float getX() const;
        float getY() const;
        void setX(Fixed x);
        void setY(Fixed y);
};

triangle::triangle() : x(0), y(0) {
}

triangle::triangle(Fixed x, Fixed y) : x(x), y(y) {
}

triangle::triangle(const triangle &copy) : x(copy.x), y(copy.y) {
}

triangle &triangle::operator=(const triangle &copy) {
    if (this != &copy) {
        this->x = copy.x;
        this->y = copy.y;
    }
    return *this;
}

triangle::~triangle() {
}

float triangle::getX() const { return x.toFloat(); }
float triangle::getY() const { return y.toFloat(); }

void triangle::setX(Fixed x) {
    this->x = x;
}

void triangle::setY(Fixed y) {
    this->y = y;
}

