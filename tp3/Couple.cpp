#include <iostream>

#include "Couple.hpp"
#include "Bavarde.hpp"

int Couple::counter = 0;

Couple::Couple()
{
    counter++;
    b1 = Bavarde();
    b2 = Bavarde();
    num  = counter;
}


Couple::Couple(Bavarde inB1, Bavarde inB2):b1(inB1), b2(inB2)
{
    counter++;
    num = counter;
} 



Couple::~Couple()
{
    std::cout << "Destruction du couple " << num << std::endl;

}


