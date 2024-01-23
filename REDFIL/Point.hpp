#ifndef POINT_HPP
#define POINT_HPP

class Point 
{
    int x;
    int y;

    public:
        Point(int xCoord, int yCoord);
        int getX(void);
        int getY(void);
};

#endif