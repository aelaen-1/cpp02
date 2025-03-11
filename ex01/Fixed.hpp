#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed(void);
    Fixed(const Fixed& other);
    ~Fixed(void);
    Fixed& operator=(const Fixed& other);
    int getRawBits(void) const;
    void    setRawBits(int const raw);

    Fixed(int const n);
    Fixed(float const f);
    float   toFloat(void) const;
    int     toInt(void) const;

private:
    int _rawBits;
    static int const _fracBitCount;
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif