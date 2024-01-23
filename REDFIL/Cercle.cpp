#include <iostream>
#include <sstream> 

#include "Rectangle.hpp"
#include "Cercle.hpp"
#include "Point.hpp"

using namespace std;

Cercle::Cercle(int cx, int cy, int r): Rectangle(Point(cx, cy), 2 * r, 2 * r)
{
    rayon = r;
}

string Cercle::toString(void) 
{  
    ostringstream oss;
    oss << "CERCLE " << getPoint().getX() << " " << getPoint().getY() << " "
            << rayon;
    return oss.str();
}
