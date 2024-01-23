#include <iostream>
#include "Cercle.hpp"
#include "Point.hpp"
#include "Rectangle.hpp"

using namespace std;

int main() {
    // Exemple d'utilisation de la classe Rectangle
    Point p(30, 30);
    Rectangle rectangle(p, 5, 7);

    Cercle cercle(5, 5 ,3);
    // Affichage des propriétés du Rectangle
    cout << rectangle.toString() << endl;

    // Affichage propriétés du Cercle
    cout << cercle.toString() << endl;
    return 0;
}