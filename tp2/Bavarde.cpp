#include <iostream>

class Bavarde {
  int n;

  public:
        Bavarde();
        Bavarde(int);
        ~Bavarde();

        int get(void);

} bizarre(1);  

// Objet bavarde globale
Bavarde globale(2);

// Constructeur
Bavarde::Bavarde():n(0)
{
    std::cout << "Construction de " << n  << std::endl;
}

Bavarde::Bavarde(int in):n(in)
{
    std::cout << "Construction de " << n  << std::endl; 
}

// Getter
int Bavarde::get(void)
{
    return n;
}

// Destructeur
Bavarde::~Bavarde() 
{
    std::cout << "Tais toi " << n << std::endl;
}

void fonction(Bavarde b)
{
  std::cout << "code de la fonction" << std::endl;
}

int main(int, char **) 
{
  Bavarde b1(3);
  Bavarde b2(4);
  Bavarde * p = new Bavarde(5);

  fonction(b1);

  // delete pour * p 
  delete p;

  // 1. Qu'est-ce que bizzare ?
  // = instance globale de Bavarde avec n = 1.

  // 2. Destruction des objets 
  // Les objets globaux sont détruits dans l'ordre inverse de leur déclaration

  /**
    *     Pourquoi peut-on voir plus de destructions que de constructions ?
    *     Une instance est détruite mais la construction n'est pas signalée. 
    *     C'est donc qu'il y a une construction implicite quelque part. 
    *     Cela sera abordé en cours : le C++ passe les variables par valeur (copie) comme en C.
  */


  /**
        Lorsqu'un objet est passé par valeur à une fonction, une copie de l'objet est effectuée.
        Cette copie est détruite lorsque la fonction se termine, augmentant ainsi le nombre total de destructions.
  */

  std::cout << "Appel getter (n) - constructeur puis --> appel au getter : \n" << Bavarde(0).get() << std::endl;

  return 0;
}