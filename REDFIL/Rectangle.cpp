#include <iostream>
#include <sstream> 
#include "Rectangle.hpp"

using namespace std;

Rectangle::Rectangle(Point p, int w, int h): upperLeftPoint(p), width(w), height(h){}

string Rectangle::toString(void)
{
    ostringstream oss;
    oss << "RECTANGLE " << upperLeftPoint.getX() << " " << upperLeftPoint.getY() << " "
            << width << " " << height;
    return oss.str();
}



Point Rectangle::getPoint(void){
    return upperLeftPoint;
}
