#include <iostream>
#include <cstdlib>

#include "Bavarde.hpp"
#include "Couple.hpp"
#include "Famille.hpp"
#include "Fille.hpp"



int main(int, char **) 
{
  /*const int TAILLE = 20;
  Bavarde   tab1[TAILLE];
  Bavarde * tab2 = new Bavarde[TAILLE];
  // Combien d'instances sont créées ?

  for (int i =0; i < TAILLE; ++i) {
     tab1[i].afficher();
     tab2[i].afficher();
  }

  // Combien d'instances sont détruites ? => 20 instances
  // Il manque les instances de tab2 

  delete [] tab2;*/


  //Couple c1 = Couple();
/*
    Couple c2{Bavarde(), Bavarde()} ;
    //  l'ordre de création est bien l'inverse de l'ordre de destruction
    
    Famille f1 = Famille(5);

    Bavarde * bmall = (Bavarde*) malloc(sizeof(Bavarde));
    std::cout << " Valeur du Bavarde avec malloc. : " << bmall->get() << std::endl;
    // La valeur de l'objet avec malloc = 0 (ne prends pas en compte le compteur statique)
    Bavarde * bnew  = new Bavarde();
    std::cout << " Valeur du Bavarde avec  new. : " << bnew->get() << std::endl;
    // La valeur de l'objet avec new prends en compte le compteur statique pour l'id. de Bavarde

    // free => n'appelle pas le destructeur
    // malloc => n'appelle pas le constructeur
    // delete => marche avec malloc
*/


    /*Fille fille1 = Fille();
    fille1.afficherNumeroMere();
    Fille fille2 = Fille();
    Fille fille3 = Fille();
    fille3.afficherNumeroMere();

    Mere m1 = Mere();
    std::cout << "Appel de getCompteur() dans Mere : " << m1.getCompteur() << std::endl;
    std::cout << "Appel de getCompteur() sans objet : " << Mere::getCompteur() << std::endl;*/


    Mere m2{"Cynthia"};
    std::cout << "Nom de la mere : " << m2.getNom() << std::endl;

    /**
    * Le constructeur avec paramètre de Mere n'a pas été hérité. Il faut en écrire un pour Fille. 
    * En C++11, il est possible de récupérer les constructeurs de la classe mère.
    */

    Fille f2{"Louane"};
    std::cout << "Nom de la mere (appel à partir de la fille) : " << f2.getNom() << std::endl;
    

    // Si on ne specifie pas explicitement le constructeur de Mere
    std::string isEmpty = f2.getNom().empty() ? "true": "false";
    std::cout << "Nom de la mere (appel non explicite) : " << isEmpty << std::endl;

    // Affichage classe
    std::cout << " Classe de m2 : ";
    m2.afficherClasse();
    std::cout << " Classe de f2 : ";
    f2.afficherClasse();


    // Tests
    std::cout << "=== TEST : Affichage des classes ===" << std::endl;
    Mere  *pm = new Mere("mere_dyn");
    Fille *pf = new Fille("fille_dyn");
    Mere  *pp = new Fille("fille vue comme mere");
    pm->afficherClasse(); // affiche Mere
    pf->afficherClasse(); // affiche Fille
    pp->afficherClasse(); // affiche Fille

    return 0;
}
