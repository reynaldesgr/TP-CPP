#ifndef __MERE_HPP__
#define __MERE_HPP__

#include <iostream>
#include <string>


class Mere 
{
    static int counter;

    protected:
        int num;
        std::string nom;

    public:
        Mere();
        Mere(const std::string&);
       ~Mere();
        std::string getNom(void);
        virtual void afficherClasse(void);
    
        static int getCompteur(void); 
};

#endif // __MERE_HPP__


