//
// Created by resegerie on 29/11/2023.
//
#ifndef TP_CPP_POINT_HPP
#define TP_CPP_POINT_HPP

#include <iostream>

using namespace std;

class Point
{
    // Attribut de classe
    static int compteur;

    // par défaut, tout est privé dans une "class"
    int x;
    int y;
    int privAttr;

public:

    // Constructeurs
    Point();
    Point(int x, int y);

    static void printCompteur(void);
    static int  getCompteur(void);

    int  getX        (void);
    int  getY        (void);
    void setX        (int newX);
    void setY        (int newY);

    void deplacerVers(int newX, int newY);
    void deplacerDe  (int dX, int dY);

};

#endif //TP_CPP_POINT_HPP
