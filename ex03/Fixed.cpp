#include "Fixed.hpp"

int const   Fixed::_fracBitCount = 8;

Fixed::Fixed(void)
: _rawBits(0)
{
}
Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed::~Fixed(void)
{
}

Fixed& Fixed::operator=(const Fixed& other)
{
    _rawBits = other.getRawBits(); 
    return (*this); // on retourne une réf, et this est un ptr
}

int Fixed::getRawBits(void) const
{
    return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}


std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
    os << other.toFloat();
    return (os);
}

Fixed::Fixed(int const n)
{
    _rawBits = n << _fracBitCount;
}

Fixed::Fixed(float const f)
{
    _rawBits = roundf(f * (1 << _fracBitCount));
}

float   Fixed::toFloat(void) const
{
    return float(_rawBits) / float(1 << _fracBitCount); // conserve partie fractionnaire
}

int     Fixed::toInt(void) const
{
    return _rawBits >> _fracBitCount; // tronque la partie fractionnaire
}


/*            comparison operators overload           */
bool    Fixed::operator>(const Fixed& other) const
{
    return _rawBits > other.getRawBits();
}

bool    Fixed::operator<(const Fixed& other) const
{
    return _rawBits < other.getRawBits();
}

bool    Fixed::operator>=(const Fixed& other) const
{
    return _rawBits >= other.getRawBits();

}
bool    Fixed::operator<=(const Fixed& other) const
{
    return _rawBits <= other.getRawBits();

}

bool    Fixed::operator==(const Fixed& other) const
{
    return _rawBits == other.getRawBits();

}
bool    Fixed::operator!=(const Fixed& other) const
{
    return _rawBits != other.getRawBits();
}

/*            arithmetic operators overload        */
Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (!other.getRawBits())
        return (std::cout << "You cannot by zero.\n", 0);
    return Fixed(this->toFloat() / other.toFloat());
}

//prefix incrementation
Fixed&   Fixed::operator++()
{
    this->setRawBits(_rawBits + 1);
    return *this;
}
//postfix incrementation

Fixed   Fixed::operator++(int)
{
    Fixed   tmp = *this;
    this->setRawBits(_rawBits + 1);
    return tmp;
}

//prefix decrementation
Fixed&  Fixed::operator--()
{
    this->setRawBits(_rawBits - 1);
    return *this;
}

//postfix decrementation
Fixed   Fixed::operator--(int)
{
    Fixed   tmp = *this;
    this->setRawBits(_rawBits - 1);
    return tmp;
}

Fixed Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

Fixed Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    return b; 
}

Fixed Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

Fixed Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    return b;
}