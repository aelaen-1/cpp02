#include "Point.hpp"

Point::Point()
: x(0), y(0)
{
}

Point::Point(const float float1, const float float2)
: x(float1), y(float2)
{
}

Point::Point(const Point& other)
{
    *this = other;
}

Point::~Point()
{
}

Point& Point::operator=(const Point& other)
{
    Point   point(other);
    if (this != &other) {
        const_cast<Fixed&>(this->x) = other.x;// const_cast pas génial
        const_cast<Fixed&>(this->y) = other.y;// Utilisation directe des membres (mm classe, pas de getter)
    }
    return *this;
}

const Fixed Point::getX() const
{
    return this->x;
}

const Fixed Point::getY() const
{
    return this->y;
}
