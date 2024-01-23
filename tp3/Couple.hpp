#ifndef __COUPLE_HPP__
#define __COUPLE_HPP__


#include "Bavarde.hpp"

class Couple 
{
    static int counter;

    int num;

    Bavarde b1;
    Bavarde b2;

    public:
        Couple();
        Couple(Bavarde, Bavarde);
        ~Couple();  

};


#endif // __COUPLE_HPP__


