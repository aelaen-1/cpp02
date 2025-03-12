#include "Fixed.hpp"

int const   Fixed::_fracBitCount = 8;

Fixed::Fixed(void)
: _rawBits(0)
{
    std::cout << "Default constructor called"<<std::endl;
}
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
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
    std::cout << "Int constructor called\n";
    _rawBits = n << _fracBitCount;
}

Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called\n";
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