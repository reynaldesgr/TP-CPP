#include <iostream>

#include "Fille.hpp"

int Fille::counter = 0;

Fille::Fille():Mere()
{

    counter++;
    num = counter;

    std::cout << "Construction de Fille " << num << std::endl;
}


Fille::Fille(const std::string& nom)
{
    counter++;
    num = counter;

    std::cout << "Construction de Fille " << num << std::endl;
} 



Fille::~Fille()
{
    std::cout << "Destruction de Fille " << num << std::endl;
}


void Fille::afficherNumeroMere()
{
    std::cout << "ID. de Mere : " << Mere::num << std::endl;
    std::cout << "Appel de getCompteur() Mere dans Fille : " << Mere::getCompteur() << std::endl;
}

void Fille::afficherClasse()
{
    std::cout << "Je suis de la classe Fille" << std::endl;
}


