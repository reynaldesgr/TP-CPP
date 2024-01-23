#include <iostream>

#include "Bavarde.hpp"

int Bavarde::counter = 0;
// Constructeur Bavarde avec liste d'initialisation
Bavarde::Bavarde():num(counter++)
{
    std::cout << "Construction de " << num  << std::endl;
}

// Constructeur Bavarde avec liste d'initialisation
Bavarde::Bavarde(int in):num(in)
{
    counter++;
    std::cout << "Construction de " << num  << std::endl; 
}

Bavarde::Bavarde(const Bavarde& b)
{
    counter++;
    if (num) num = b.num;
}


// Getter
int Bavarde::get(void)
{
    return num;
}

// Destructeur
Bavarde::~Bavarde() 
{
    std::cout << "Tais toi " << num << std::endl;
}

void Bavarde::fonction(Bavarde b)
{
  std::cout << "code de la fonction" << std::endl;
}

void Bavarde::afficher()
{
  std::cout << "Affichage de Bavarde " << num << std::endl; 

}