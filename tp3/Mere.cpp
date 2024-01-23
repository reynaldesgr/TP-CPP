#include <iostream>
#include <string>

#include "Mere.hpp"

int Mere::counter = 0;


Mere::Mere()
{
    counter++;
    num = counter;

    std::cout << "Construction de Mere " << num << std::endl;
}


Mere::Mere(const std::string& inNom):nom(inNom)
{
    counter++;
    num = counter;

    std::cout << "Construction de Mere " << num << std::endl;

}


Mere::~Mere()
{
    std::cout << "Destruction de Mere " << num << std::endl;
}


int Mere::getCompteur()
{
    return counter;
}

std::string Mere::getNom()
{
    return nom;
}

void Mere::afficherClasse()
{
    std::cout << "Je suis de la classe Mere" << std::endl;
}



