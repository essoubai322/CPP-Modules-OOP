#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private :
        int value;
        static const int fractional;
    public :
        Fixed();
        Fixed( const Fixed &copy );
        Fixed &operator=(const Fixed &copy);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif