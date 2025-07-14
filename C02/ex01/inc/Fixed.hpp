#pragma once
#include <iostream>

class   Fixed
{
    public:
        
        Fixed(void);
        Fixed(const Fixed& copy);
        Fixed(const int n);
        Fixed(const float f);
        ~Fixed(void);

        Fixed&          operator = (const Fixed& copy);
        
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

    private:
        
        int                 value;
        static const int    nFractBits = 8;
};

std::ostream&   operator << (std::ostream& os, const Fixed& fixed);