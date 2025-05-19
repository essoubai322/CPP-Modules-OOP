#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cstring>
#include <cmath>

class Fixed
{
    private: 
        int nam;
        static const int frac;
    public:
        Fixed();
        ~Fixed();
        Fixed &operator=(const Fixed &test);
        Fixed(const Fixed &copy);
        Fixed(const int a);
        Fixed(const float a);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
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
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

#endif