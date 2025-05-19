#ifndef FIXED_HPP
#define FIXED_HPP

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
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif