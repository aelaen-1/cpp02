#include "Fixed.hpp"

int const   Fixed::_fracBitCount = 8;

Fixed::Fixed()
: _rawBits(0)
{
    std::cout << "Default constructor\n";
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
    std::cout << "getRawBits member function\n";
    return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}