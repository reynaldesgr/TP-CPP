#include <iostream>

#include "Pile.hpp"


Pile::Pile():tab(nullptr), taille(0), capacite(10)
{
    if (capacite <= 0)
    {
        throw std::invalid_argument("Invalid capacity.");
            
    } 
    tab = new int[capacite]; 
}

Pile::Pile(int inCapacite):tab(nullptr), taille(0), capacite(inCapacite)
{
    if (capacite <= 0)
    {
        throw std::invalid_argument("Invalid capacity.");
    } 
    tab = new int[capacite]; 
}


const int& Pile::size() const
{
    return taille;
}

const int& Pile::top() const 
{
    if (taille > 0)
    {
        return tab[taille - 1]; 
    }
    throw std::out_of_range("Stack is empty."); 
}


bool Pile::isEmpty() const 
{
    return (taille == 0);
} 

void Pile::pop()
{
    if (taille == 0)
    {
        throw std::invalid_argument("Invalid size.");
    } 
    --taille;
}

void Pile::push(const int& el)
{
    tab[taille] = el;
    ++taille; 
}

Pile::~Pile()
{
    delete [] tab; 
}












