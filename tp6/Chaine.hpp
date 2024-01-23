#ifndef CPP5__CHAINE_HPP
#define CPP5__CHAINE_HPP

#include <iostream>
#include <fstream>
#include <string>

class Chaine  
{

    static int compteur;

    int    capa;
    char * tab;

    public: 
        // Implémentation de la classe OutOfRangeException qui hérite de std::out_of_range
        class OutOfRangeException: public std::out_of_range
        {
            public:
                // Constructeur de notre exception avec une std::string
                OutOfRangeException(std::string inString) : std::out_of_range(inString){} 
        }; 

        // Implémentation de la classe OutOfRangeException qui hérite de std::bad_alloc
        class BadAllocException : public std::bad_alloc
        {
            public:
                BadAllocException() : std::bad_alloc(){} 
        };

    public:
        Chaine();
        Chaine(int);
        Chaine(const char *);
        Chaine(const Chaine&);
       ~Chaine();

       int              getCapacite(void) const;
       static int       getCompteur(void);
       const  char *    c_str(void) const;
       void             afficherParValeur(Chaine) const;
       void             afficher(std::ostream&) const;
       void             afficher(const Chaine&) const;
       void             afficher(void) const;

       char&                 operator[](int) const;
       Chaine&               operator= (const Chaine&);
       char&                 at        (int) const;

       // car fonction
       friend std::ostream&  operator<<(std::ostream& o, const Chaine& c);
       friend Chaine         operator+(const Chaine &a, const Chaine &b);
};


class null_pointer : public std::logic_error
{
    public:
        null_pointer() : std::logic_error("null_pointer"){} 
}; 
#endif

// at() : verification des limites / index limite
// []   : pas de verification des limites / index limite
