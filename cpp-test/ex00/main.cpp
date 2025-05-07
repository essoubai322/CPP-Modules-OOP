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
        Fixed operator=(Fixed test);
        Fixed(Fixed &copy);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

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
Fixed Fixed::operator=(Fixed test)
{
    std::cout << "Copy assignment operator called" << std::endl;
    return (test);
}

Fixed::Fixed(Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

const int Fixed::frac = 8;

int main( void ) {
    Fixed a;
    Fixed b( a );
    // Fixed c;
    // c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    // std::cout << c.getRawBits() << std::endl;
    return 0;
    }