#include <iostream>
#include "A.hpp"
#include "B.hpp"


void A::send(B * obj)
{
    obj->exec(5);
}


void A::exec(int received)
{
    i = received;
}


int main(int, char**)

{
    A a;
    B b;

    a.send(&b);
    std::cout << b.j << std::endl;


    b.send(&a);
    std::cout << a.i << std::endl;

}




