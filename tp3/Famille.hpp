#ifndef __FAMILLE_HPP__
#define __FAMILLE_HPP__

#include "Bavarde.hpp"

class Famille
{
    static int counter;
    int num;

    int length;
    Bavarde * tab;

    public:
        Famille(int);
       ~Famille(); 
};

#endif
