// Rectangle

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Point.hpp"

using namespace std;

class Rectangle
{
    Point upperLeftPoint;
    int width;
    int height;

    public:
        Rectangle(Point p, int w, int h);
        string toString(void); 
        Point getPoint(void);
};

#endif