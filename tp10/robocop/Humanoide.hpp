#ifndef HUMANOIDE_HPP
#define HUMAIN_HPP

#include "Humain.hpp"
#include "Machine.hpp"


class Humanoide : public Humain, public Machine
{

    public:
        Humanoide(std::string nom, std::string type, Genre genre, int age, int itfixit):Humain(nom, genre, age), Machine(type, 2*24*3600, itfixit){} 
};

#endif // ! HUMANOIDE_HPP

