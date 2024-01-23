#include <iostream>

#include "Famille.hpp"


int Famille::counter = 0;


Famille::Famille(int inLength)
{
    length = inLength;
    num    = counter;

    if (length >= 0)
    {
        tab    = new Bavarde[length];
    }
    else
    {
        tab    = new Bavarde[0]; 
    } 
}


Famille::~Famille()
{
    std::cout << "Destruction de la famille " << num << std::endl;
}

 



