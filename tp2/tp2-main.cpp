#include <iostream>
#include "Point.hpp"

using namespace std;

int main(int, char**)
{  
   // TP2.
   // Q1.
   Point p;
   p.setX(42);
   p.setY(52);
   cout << "x (p) : " << p.getX() << endl;
   cout << "y (p) : " << p.getY() << endl;

   Point p2 = Point(45, 55);
   cout << "x (p2) : " << p2.getX() << endl;
   cout << "y (p2) : " << p2.getY() << endl;

   Point p3 = Point{};
   cout << "x (p3) : " << p3.getX() << endl; // 0.
   cout << "y (p3) : " << p3.getY() << endl; // 0.

   Point * p4 = new Point;
   cout << "x (p4) : " << p4->getX() << endl; // 0.
   cout << "y (p4) : " << p4->getY() << endl; // 0.

   Point * p5 = new Point(100, 200);
   cout << "x (p5) : " << p5->getX() << endl; // 100.
   cout << "y (p5) : " << p5->getY() << endl; // 200.

   
   Point p6 = Point{65, 75};
   cout << "x (p6) : " << p6.getX() << endl;
   cout << "y (p6) : " << p6.getY() << endl;
   

   /** APPEL ACCESS. & METHODES DE CLASSE **/
   Point::printCompteur();
   cout << "Recuperation du compteur : " << Point::getCompteur() << endl;
   
    /* Ordre d'exec. / de passage */
   // 1. : int x = 0;
   // 3. Point(int px){ x = px; } 
   // 2. Point(int px, int){x = px;}


   // cout << p.privAttr << endl;
   /**
    * note: declared private here : int privAttr;
    */

   /*
    * #include "fic" permet d'inclure un fichier fic à partir du répertoire courant.
    * #include <fic> permet, elle, d'inclure un fichier à partir d'un répertoire standard
    * (typiquement /usr/[local]/include ou d'un chemin donné par l'option -I (i majuscule)
    */
}