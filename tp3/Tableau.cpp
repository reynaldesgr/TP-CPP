#include <iostream>

class Tableau 
{
   int * tab;
   int taille;

 public:

    // Constructeur
   Tableau():tab(nullptr), taille(10) 
   {
        tab = new int[taille]; // si problème ?
        for (int i = 0; i < taille; i++)
        {
            tab[i] = i;
   
            tab[i] = i;
        }
   }   

   // Destructeur de Tableau (pour libérer la mémoire allouée dans tab)
   ~Tableau()
   {
        delete[] tab;
   }
   
   // Affichage
   void afficher(void);

};

// Affichage
void Tableau::afficher(void)
{
    for (int i = 0; i < taille; i++)
    {
        std::cout << tab[i] << std::endl;
    }
}

int main(int, char **)
{
   Tableau t = Tableau{};

   t.afficher();
   
   return 0;
}
