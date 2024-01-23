#ifndef ENFANT_HPP
#define ENFANT_HPP

#include "Pere.hpp"
#include "Mere.hpp"


class Enfant : public Mere, public Pere
{
    static int counter;
    int id;

}

#endif // ! ENFANT_HPP
