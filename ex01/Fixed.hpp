#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed();
    Fixed(int const n);
    Fixed(float const f);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    void    setRawBits(int const raw);
    int     getRawBits(void) const;
    int     toInt(void) const;
    float   toFloat(void) const;

private:
    int _rawBits;
    static int const _fracBitCount;
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);


#endif