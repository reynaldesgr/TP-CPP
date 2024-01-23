#include <iostream>
#include "Point.hpp"

using namespace std;

/** STATIC : attributs & méthodes de classe */
int Point::compteur = 0; // Initialization


void Point::printCompteur()
{
    std::cout << "Compteur : " << compteur << std::endl;
    //cout << x << endl;
    /**
     * error: invalid use of member ‘Point::x’ in static member function
    */
}

int Point::getCompteur()
{
    return compteur;
}
/****************************************/


Point::Point(): x(0), y(0)
{
    cout << "Constructeur par défaut." << endl;
    compteur++; 
}

Point::Point(int x, int y): x(x), y(y)
{
    cout << "Constructeur avec params. (int, int)" << endl; 
    compteur++; 
}

int Point::getX()
{
    return x;
}

void Point::setX(int newX)
{
    this->x = newX;
}

void Point::setY(int newY)
{
    this->y = newY;
}

int Point::getY()
{
    return y;
}


void Point::deplacerVers(int newX, int newY)
{
    x = newX;
    y = newY;
}

void Point::deplacerDe(int dX, int dY)
{
    x+=dX;
    y+=dY;
}
