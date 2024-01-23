#include <iostream>
#include "Point.hpp"


Point::Point(int xCoord, int yCoord):x(xCoord), y(yCoord){}


int Point::getX(){ return x; }
int Point::getY(){ return y; }