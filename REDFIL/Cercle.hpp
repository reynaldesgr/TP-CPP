#ifndef CERCLE_HPP
#define CERCLE_HPP

#include <iostream>
#include "Rectangle.hpp"

using namespace std;

class Cercle : public Rectangle
{

    int rayon;

    public:

        Cercle (int cx, int cy, int r);
        string toString(void);
        
};
#endif