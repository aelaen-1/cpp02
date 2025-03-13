#ifndef FIXED_HPP
 #define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed(void);
    Fixed(const Fixed& other);
    Fixed(int const n);
    Fixed(float const f);
    ~Fixed(void);

    Fixed& operator=(const Fixed& other);

    bool    operator>(const Fixed& other) const;
    bool    operator<(const Fixed& other) const;
    bool    operator>=(const Fixed& other) const;
    bool    operator<=(const Fixed& other) const;
    bool    operator==(const Fixed& other) const;
    bool    operator!=(const Fixed& other) const;

    Fixed   operator+(const Fixed& other) const;
    Fixed   operator-(const Fixed& other) const;
    Fixed   operator*(const Fixed& other) const;
    Fixed   operator/(const Fixed& other) const;

    Fixed&   operator++(); //prefix
    Fixed   operator++(int); //postfix

    Fixed&  operator--();
    Fixed   operator--(int);

    int getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

    static Fixed min(Fixed& a, Fixed& b);
    static Fixed min(const Fixed& a, const Fixed& b);
    static Fixed max(Fixed& a, Fixed& b);
    static Fixed max(const Fixed& a, const Fixed& b);


private:
    int _rawBits;
    static int const _fracBitCount;
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);


#endif