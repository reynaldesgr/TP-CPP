#include <iostream>

using namespace std;

const int TAILLE = 10;

class Exemple {
    public:
        void afficher()
        {
            cout << "Hello !" << endl;
        }
};

// Swap avec pointeurs
void echangerAvecPointeurs(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Swap avec references
void echangerAvecReferences(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}


void fonction1(int a)
{
    std::cout << &a << std::endl;
}

void fonction2(int& a)
{
    std::cout << &a << std::endl;
}


// Surcharge (Overloading)

void afficher(int a)
{
    printf("%d", a);
}

void afficher(double a)
{
    printf("%lf", a);
}


// Supress warnings: params muets
int main(int, char **)
{
    int i;

    // Q1.
    /*for(i = 0; i < 120; ++i)
        cout << "Bonjour les ZZ" << i / 10.0 << endl;*/

    // Q2.
    /*string s1;
    string s2;

    string s;
    cout << "Entrez une première chaine de caractère : " << endl;
    cin >> s1;
    cout << "Entrez une deuxième chaine de caractère : " << endl;
    cin >> s2;

    s = s1.compare(s2) > 0 ? s2 : s1;

    cout << "Chaîne la plus longue : " << s << endl;
    cout << "* Longueur : " << s.size();*/

    // Q3. Tableaux et constantes

    /*int tab[TAILLE];

    for (int i = 0; i < TAILLE; ++i) {
        tab[i] = i % 2;
        cout << tab[i] << " ";
    }

    cout << endl;*/

    // Si le fichier est d'extension .cpp et compilé
    // avec gcc ou bien si le fichier d'extension .c est compilé
    // avec g++, vous n'aurez pas ces messages d'erreurs

    /*afficher(1);
    afficher(2.0);*/

    // Q4. Erreur de contexte / Chaîne de caractères

    /*char s[10];

    cin >> s;

    cout << "#" << s << "#" << endl;
    for (int i = 0; i < 10; ++i)
        cout << "@" << s[i] << "@" << (int) s[i] << "@" << endl;*/

    // Le tableau s a une taille de 10 caractères,
    // mais si l'utilisateur entre une chaîne de plus de 9 caractères (car le dernier caractère est réservé pour le caractère nul \0),
    // il y aura un dépassement de tampon.

    // Correction :

    /*string s;
    cin >> s;

    cout << "#" << s << "#"<< endl;

    for (size_t i = 0; i < s.length(); ++i)
    {
        cout << "@" << s[i] << static_cast<int>(s[i]) << "@" << endl;
    }*/


    // Q5. Référence
    /*int a  = 5;
    int &r = a;

    std::cout << a << " " << r << std::endl;
    std::cin  >> a;
    std::cout << a << " " << r << std::endl;
    std::cin  >> r;
    std::cout << a << " " << r << std::endl;


    // a et r ont la même adresseen mémoire (car r est une référence sur a)
    cout << "Adresse de a : " << &a << endl;
    cout << "Adresse de r : " << &r << endl;*/

    // Si r n'est pas initialisée : Declaration of reference variable 'r' requires an initializer

    int age = 45;

    std::cout << "Adresse de age : " << &age << std::endl;
    fonction1(age); // Passage par valeur/copie : @ différente dans la fonction1
    fonction2(age); // Passage par référence : @ identique à a, car passage par référence

    // ATTENTION : la référence n'est pas un type différenciant pour le compilateur pour déterminer la surcharge

    // Q6. Echange de variables
    /*int  a = 3;
    int  b = a;
    int& c = a;

    std::cout << a << " " << b << " " << c << std::endl;
    b = 4;
    std::cout << a << " " << b << " " << c << std::endl;
    c = 5;
    // a est modifiée
    std::cout << a << " " << b << " " << c << std::endl;
    a = 6;
    // c est modifiée
    std::cout << a << " " << b << " " << c << std::endl;*/

    // Il faut initialiser la variable a
    /*int  a = 42;
    int &r = a;

    std::cout << a << " " << r << std::endl;*/

    /*int  a = 1;
    int  b = 2;
    int &r = a;

    // 1 2 1
    std::cout << a << " " << b << " " << r << std::endl;

    r = b;
    // 2 2 2
    std::cout << a << " " << b << " " << r << std::endl;

    b = 4;
    // 2 4 2
    std::cout << a << " " << b << " " << r << std::endl;

    r = 5;
    // 5 4 5
    std::cout << a << " " << b << " " << r << std::endl;*/

    // ERREUR : si &r est const cannot assign to variable 'r' with const-qualified type 'const int &'
    /*int  a = 1;
    int &r = a;

    std::cout << a << " " << r << std::endl;

    a = 2;
    std::cout << a << " " << r << std::endl;

    r=3;
    std::cout << a << " " << r << std::endl;*/

    // Q7. Pointeurs et allocation mémoire

    // Initialisation du pointeur
    /*int * p = nullptr;

    p = &a;
    std::cout << *p << " " << p;
    int * p = new int;

    *p = 3;
    cout << *p << endl;

    //Libértion de la mémoire
    delete p;*/


   /*const int TAILLE = 500;

   int * p = new int[TAILLE];
   // La présence du mot-clé auto
   // dont le sens a été modifié depuis le C qui permet de demander au compilateur de déduire le bon type de variable !

   for(auto i = 0; i< TAILLE; ++i ) p[i] = i;
   for(auto i = 0; i< TAILLE; ++i ) cout << p[i] << endl;

   // Libération de la mémoire (comme tableau : ne pas oublier les [ ] !)
   delete [] p;

   //return 0;*/

   // Q8. Langage objet ?
   Exemple e;
   // Affichera "Hello !"

   e.afficher();

   //1. si on enlève le "public" : error: 'void Exemple::afficher()' is private within this context
   //2. oublier le ";" :  error: expected ';' after class definition
   //3. avec "gcc" : pas de warnings ?

   return TAILLE;
}
