#ifndef ZZ_HPP
#define ZZ_HPP

#include <iostream>
#include <ostream>

#include <string.h>

class ZZ
{
    std::string nom, prenom;
    double note;


    public:
        ZZ(std::string, std::string, double);

        bool operator<(const ZZ& other) const
        {
            return this->note < other.note;
        }  

        friend std::ostream& operator<<(std::ostream& os, const ZZ& obj)
        {
            os << "Nom : " << obj.nom << " | Prenom : " << obj.prenom << " | Note : " << obj.note;
            return os;
        } 
};

#endif

   


