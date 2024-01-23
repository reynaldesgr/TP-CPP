#include <iostream>
#include "B.hpp"
#include "A.hpp"

void B::send(A *  obj)
{
    obj->exec(10);
}

void B::exec(int received)
{
    j = received;
}
