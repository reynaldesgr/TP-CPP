#ifndef __FILLE_HPP__ 
#define __FILLE_HPP__

#include "Mere.hpp"

class Fille : public Mere
{
    static int counter;

    int num;

    public:
        Fille();
        Fille(const std::string&);
       ~Fille(); 
       void afficherNumeroMere();
       void afficherClasse() override;
};


#endif // __FILLE_HPP__


