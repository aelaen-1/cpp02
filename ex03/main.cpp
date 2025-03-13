#include "Point.hpp"

void    testPointInTriangle(const Point& A, const Point& B, const Point& C, const Point& P)
{
    if (bsp(A, B, C, P))
        std::cout << "Point (" << P.getX() << ", " << P.getY() << ") is inside the triangle.\n";
    else
        std::cout << "Point (" << P.getX() << ", " << P.getY() << ") is outside the triangle.\n";
}

int main(void) 
{ 
    const Point A(0, 0);
    const Point B(5, 0);
    const Point C(0, 5);

    // inside
    const Point P1(1, 1);
    testPointInTriangle(A, B, C, P1);

    // outside
    const Point P2(6, 6);
    testPointInTriangle(A, B, C, P2);

    const Point P3(2.5, 0);
    testPointInTriangle(A, B, C, P3);

    const Point P4(0, 0);
    testPointInTriangle(A, B, C, P4);

    return 0;
}