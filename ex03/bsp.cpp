#include "Point.hpp"

//             C
//             P
//                 B
// A

// (AB, AP) = ((B.x - A.x, B.y - A.y), (P.x - A.x, P.y - A.y))
// ==> on considère la matrice M formée par la concaténation des matrices AB et AP
// et on calcule le déterminant : 
// det(M) = ad - bc = (B.x - A.x)(P.y - A.y) - (B.y - A.y)(P.x - A.x)
// M  = |a b|
//      |c d|
// si ce déterminant est strictement positif, P est bien à gauche de [AB]
// on veut la même chose pour [BC] et [CA] (que le point soit à gauche)
// ps: on aurait pu le faire à droite en prenant [AC] [CB] et [BA], 
// l'idée est de déterminer si l'angle est strt positif

static Fixed vectorProduct(Point const A, Point  const B, Point const P)
{
    return ((B.getX() - A.getX()) * (P.getY() - A.getY())
     - (B.getY() - A.getY()) * (P.getX() - A.getX()));
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{

    bool b1, b2, b3;

    b1 = vectorProduct(a, b, point) > 0.0f;
    b2 = vectorProduct(b, c, point) > 0.0f;
    b3 = vectorProduct(c, a, point) > 0.0f;

    return (b1 && b2 && b3);
}