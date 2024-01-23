#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <queue>
#include <map>
#include <set>
#include <stack>

#include "ZZ.hpp"

using namespace std;

// Premier elem
const string& first(const pair<string, string>& p)
{
    return p.first;
}

// Affichage map (paire())
void paire(const  map<string, string> liste)
{
    map<string, string>::const_iterator it = liste.begin();

    while (it != liste.end())
    {
        std::cout << it->first << " " << it->second << std::endl;
        ++it;
    } 
}


/**
 * Un foncteur (ou "functor" en anglais) est un objet en programmation C++ qui peut être utilisé 
 * comme une fonction. Un foncteur est défini en surchargeant l'opérateur de parenthèses () 
 * (opérateur de l'appel de fonction) dans la classe de l'objet. 
 * Cela permet à l'objet d'être invoqué comme s'il s'agissait d'une fonction.
 *
*/

int main (int argc, char ** argv) 
{

    // Tests class ZZ
    ZZ etudiant1("A", "fam", 19);
    ZZ etudiant2("B", "fam", 14);
    ZZ etudiant3("C", "fam", 17);
    ZZ etudiant4("Z", "fam", 12);

    if (etudiant1 < etudiant2)
    {
        std::cout << "L'etudiant 1 a une note inf. a etudiant 2." << std::endl;
    } 
    else
    {
        std::cout << "L'etudiant 1 a une note inf. a etudiant 2." << std::endl;
    } 


    // priority-queue
    using vzz = std::vector<ZZ>;

    vzz zz;
    std::priority_queue<ZZ> tri;

    zz.push_back(etudiant1);
    zz.push_back(etudiant2);
    zz.push_back(etudiant3);
    zz.push_back(etudiant4);

    /*for (vzz::iterator it = zz.begin(); it != zz.end(); ++it)
    {
        tri.push(*it);
    } 


    while (!tri.empty())
    {
        std::cout << tri.top() << " " << std::endl;
        tri.pop();
        
    }*/

    std::sort(zz.begin(), zz.end(), CompareZZByGrade());

    for (const ZZ& etud : zz)
    {
        std::cout << "Nom : " << etud.nom << " | Prénom : " 
        << etud.prenom << " | Note : " 
        << etud.note << std::endl;
    } 

    // Ordre lexico. + ordre inverse des notes
    priority_queue<ZZ, vector<ZZ>, CompareByName>       namePriorityQueue;
    priority_queue<ZZ, vector<ZZ>, CompareInvZZByGrade> scoreInvPriorityQueue;

    // Remplissage des files de priorités
    for (const ZZ& etud : zz)
    {
        namePriorityQueue.push(etud);
        scoreInvPriorityQueue.push(etud);
    }

    std::cout << "Ordre lexicographique" << std::endl;

    while (!namePriorityQueue.empty())
    {
        cout << namePriorityQueue.top() << endl;
        namePriorityQueue.pop();
    }

    std::cout << "Ordre inverse des notes" << std::endl;

    while (!scoreInvPriorityQueue.empty())
    {
        cout << scoreInvPriorityQueue.top() << endl;
        scoreInvPriorityQueue.pop();
    }

    // set : afficher les zzs dans l'ordre lexicographique
    std::cout << " Set : ZZ " << std::endl;

    std::set<ZZ> set;

    set.insert(etudiant1);
    set.insert(etudiant2);
    set.insert(etudiant3);
    set.insert(etudiant4);

    for (const ZZ& etud : set)
    {
        cout << "Nom : " << etud.nom << " | Prenom : " 
        << etud.prenom << " | Note : " 
        << etud.note << std::endl;
    }


    // Rand_0_100
    vector<int> v1 (50);
    
    // generate
    cout << "GENERATE" << endl;
    generate(v1.begin(), v1.end(), Rand_a_b(0, 100));

    vector<int>::iterator it1;
    for (it1 = v1.begin(); it1 != v1.end(); ++it1)
    {
        cout << *it1 << " " << endl;
    }

    // generate_n
    cout << "GENERATE_N" << endl;
    vector<int> v2 (50);

    generate_n(v2.begin(), 50, Rand_a_b(0, 100));

    vector<int>::iterator it2;
    for (it2 = v1.begin(); it2 != v1.end(); ++it2)
    {
        cout << *it2 << " " << endl;
    }

    // back_inserter
    cout << "BACK_INSERTER" << endl;
    vector<int> v3;

    copy(v3.begin(), v3.end(), back_inserter(v1));

    vector<int>::iterator it3;
    for (it3 = v1.begin(); it3 != v1.end(); ++it3)
    {
        cout << *it3 << " " << endl;
    }


    // accumulate
    // à remplacer par v1, v2 ou v3
    vector<int> s = {1, 2, 3, 4, 5};

    int sum = accumulate(s.begin(), s.end(), 0);

    double average = sum / s.size();

    std::cout << "Somme : " << sum << std::endl;
    std::cout << "Moyenne : " << average << std::endl;


    // min_element, max_element

    // auto <=> déduit automatiquement le type des variables
    auto min = min_element(s.begin(), s.end());
    auto max = max_element(s.begin(), s.end());

    std::cout << "Minimum  : " << *min << std::endl;
    std::cout << "Maximum  : " << *max << std::endl;


    // Foncteur de Fibonacci
    int n = 4;

    int number = Fibonacci_n()(n);

    std::cout << "Le nombre de Fibonacci à l'indice " << n << " est : " << number << std::endl;

    // Vector
    vector<int> v;

    for (int i = 1; i <= 100; i++)
    {
        v.push_back(i);
    }

    // shuffle
    random_shuffle(v.begin(), v.end());

    vector<int>::iterator it4;
    for (it4 = v.begin(); it4 != v.end(); ++it4)
    {
        cout << *it4 << " " << endl;
    }

    int target = 50;
    auto it = find(v.begin(), v.end(), target);

    if (it != v.end())
    {
        cout << "Liste à partir de l'élément " << target << " : ";
        for_each(it, v.end(), [](int num) { cout << num << " " << endl; });
    }

    // comparateur de chaines
    vector<string> strings = {"apple", "banana", "cherry", "date", "fig"};

    // tri des chaines de caracteres
    sort(strings.begin(), strings.end(), SortFonc());

    for (const std::string& str : strings) 
    {
        cout << str << " ";
    }
    cout << endl;

    // majusucules
    ToUpperCase toUpper;

    toUpper(strings);
    for (const std::string& str : strings) 
    {
        cout << str << " ";
    }
    cout << endl;

  return 0;
}
