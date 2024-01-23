#include <iostream>

#include "Bavarde.hpp"



void test1(Bavarde b)
{
    std::cout << "appel de fonction avec parametre objet et copie" << std::endl;
}


Bavarde test2a()
{
    std::cout << "appel de fonction avec retour" << std::endl;
    return Bavarde();
}


Bavarde test2b()
{
    Bavarde b;
    std::cout << "appel de fonction avec retour" << std::endl;
    return b;
}

void test3(Bavarde& b)
{
    std::cout << "appel de fonction avec référence" << std::endl;
}

void test4(Bavarde *b)
{
    std::cout << "appel de fonction avec un pointeur sur un objet" << std::endl;
}


int main (int, char**)
{
    Bavarde b;
    test1(b);
    test2a();
    test2b();
    test3(b);
    test4(&b);
    return 0;
}

