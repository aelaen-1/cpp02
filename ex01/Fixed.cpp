#include "Fixed.hpp"

int const   Fixed::_fracBitCount = 8;

Fixed::Fixed()
: _rawBits(0)
{
    std::cout << "Default constructor\n";
}

Fixed::Fixed(int const n)
{
    std::cout << "Integer constructor\n";
    _rawBits = n << _fracBitCount;
}

Fixed::Fixed(float const f)
{
    std::cout << "Float constructor\n";
    _rawBits = roundf(f * (1 << _fracBitCount));
}
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor\n";
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Default destructor\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator\n";
    _rawBits = other.getRawBits(); 
    return (*this);
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

float   Fixed::toFloat(void) const
{
    return float(_rawBits) / float(1 << _fracBitCount); // conserve partie fractionnaire
}

int     Fixed::toInt(void) const
{
    return _rawBits >> _fracBitCount; // tronque la partie fractionnaire
}