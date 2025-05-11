#include <iostream>
#include <cstring>

class Fixed
{
    private: 
        int nam;
        static const int frac;
    public:
        Fixed();
        ~Fixed();
        Fixed &operator=(Fixed &test);
        Fixed(Fixed &copy);
        Fixed(const int a);
        Fixed(const float a);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

Fixed::Fixed(const int a)
{
    this->nam = a;
}

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

const int Fixed::frac = 8;

int main( void ) 
{

}