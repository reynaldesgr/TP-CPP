#ifndef HUMAIN_HPP
#define HUMAIN_HPP

#include <iostream>
#include <string>

#include "Genre.hpp"

class Humain
{
    std::string nom;
    Genre genre;
    int age;

    public:
        Humain(std::string nom, Genre genre, int age):nom(nom), genre(genre), age(age){}   
        const std::string getNom  () const { return nom;  }
        Genre             getGenre() const { return genre;}
        int               getAge  () const { return age;  } 

        void              setNom  (std::string inNom) { nom   = inNom;   } 
        void              setGenre(Genre inGenre)     { genre = inGenre; } 
        void              setAge  (int inAge)         { age   = inAge;   }    
};


#endif // ! HUMAIN_HPP

