#include <iostream>
#include "GTemplate.hpp"
#include "Mere.hpp"
#include "Fille.hpp"

int main(int, char**)
{
    Stats<int> is;

    is.push_back(3);
    is.push_back(4);
    is.push_back(2);
    is.compute();
    is.display();


    Mere<int> mere(5);
    mere.f();

    Fille<int> fille(10);
    fille.m();
    return 0;
}
