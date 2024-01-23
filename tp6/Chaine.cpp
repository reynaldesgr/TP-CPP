#include "Chaine.hpp"
#include <cstring>
#include <sstream>


int Chaine::compteur = 0;

Chaine::Chaine():capa(-1), tab(nullptr){ compteur++; } 

Chaine::Chaine(int pCapa): capa(pCapa > 0 ? pCapa : 0)
{
    compteur++;
    try {
        if (capa)
        {
            tab = new char[capa]; 
            tab[0] = 0; // Pour marquer la fin de la cdc 
        }
        else
        {
            tab = nullptr;
        } 
    } 
    catch (const std::bad_alloc& e)
    {
        delete [] tab; // Liberation de la mémoire (meme si tab null / si le bad_alloc vient de tab) 
         
        throw BadAllocException();
    } 
}

Chaine::Chaine(const Chaine &uC)
{
    compteur++;
    capa = uC.capa;

    std::cout << "Appel constructeur par copie" << std::endl;
    
    if (capa)
    {
        tab = new char[capa]; 
        strcpy(tab, uC.tab); // bib. cstring
    } 
    else
    {
        capa = -1;
        tab  = nullptr; 
    } 
}


Chaine::Chaine(const char * cstr)
{
    compteur++;
    if (cstr)
    {
        capa = strlen(cstr) + 1; // pour compter le '\0' ou 0
        tab  = new char[capa];
        strcpy(tab, cstr);
    } 
    else
    {
        capa = -1;
        tab  = nullptr;
    } 
}

void Chaine::afficherParValeur(Chaine c) const
{
    c.afficher();
}

void Chaine::afficher(std::ostream &o) const
{
    if (tab) o << tab;
}

void Chaine::afficher() const
{
    std::cout << tab;
}

void Chaine::afficher(const Chaine& c) const
{
    std::cout << c.c_str();
}

Chaine::~Chaine(void)
{
    compteur--;
    delete [] tab; 
}

int Chaine::getCompteur() 
{
    return compteur;
}


int Chaine::getCapacite() const
{
    return capa;
}

const char * Chaine::c_str() const
/* const à la fin de la signature signifique que la fonction ne modifie pas l'état de l'objet sur lequel elle est appelée 
   (peut être appelée sur des objetts const en consequence)*/
{
    return tab;
}

Chaine& Chaine::operator=(const Chaine &uC)
{
    if (&uC != this)
    {
        delete [] tab;
        capa = uC.capa;
        if (capa)
        {
            tab = new char[capa];
            strcpy(tab, uC.tab);  
        }  
        else
        {
            tab  = nullptr;
            capa = -1; 
        }      
    } 
    return *this;
}

std::ostream& operator<<(std::ostream &o, const Chaine &c)
{
   if (c.c_str()) o << c.c_str();

   /*if (c.c_str())
   {
        const char * t = c.c_str();

        for (unsigned int i = 0; i < strlen(t); i++)
        {
            o << t[i] << std::endl;
        }
   }*/

    return o;
}


char& Chaine::operator[](int index) const
{
    if (!tab) throw null_pointer();

    if ( (index < 0) || (index >= capa) || !tab )
    {
        throw OutOfRangeException("Invalid index.");
    }

    return tab[index];

}


char& Chaine::at(int index) const
{
    if ( (index < 0) || (index >= capa) || !tab )
    {
        throw OutOfRangeException("Invalid index.");
    }

    return tab[index];
}


Chaine operator+(const Chaine &a, const Chaine &b)
{
    char * tab = new char[a.getCapacite() + b.getCapacite() - 1];
    strcpy(tab, a.c_str());
    strcat(tab, b.c_str());
    Chaine temp(tab);

    delete [] tab;

    return temp;
}