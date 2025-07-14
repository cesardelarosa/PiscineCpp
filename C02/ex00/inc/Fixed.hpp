#pragma once

class   Fixed
{
    public:
        
        Fixed(void);
        Fixed(const Fixed& copy);
        Fixed&   operator = (const Fixed& copy);
        ~Fixed(void);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        
    private:
        
        int                 value;
        static const int    nFractBits = 8;
};