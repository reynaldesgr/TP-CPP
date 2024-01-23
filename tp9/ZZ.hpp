#ifndef ZZ_HPP
#define ZZ_HPP

#include <algorithm>
#include <cctype>
#include <iostream>
#include <ostream>
#include <random>
#include <string.h>

class ZZ
{
    public:
        std::string nom, prenom;
        double note;

    public:
        ZZ(std::string, std::string, double);

        /*bool operator<(const ZZ& other) const
        {
            return this->note < other.note;
        }*/

        bool operator<(const ZZ& other) const
        {
            return this->nom < other.nom;
        } 

        friend std::ostream& operator<<(std::ostream& os, const ZZ& obj)
        {
            os << "Nom : " << obj.nom << " | Prenom : " << obj.prenom << " | Note : " << obj.note;
            return os;
        } 
};

// Foncteur de comparaison
class CompareZZByGrade
{
    public:
        bool operator()(const ZZ& zz1, const ZZ& zz2) const
        {
            return zz1.note < zz2.note; 
        } 
};

class CompareInvZZByGrade
{
    public:
        bool operator()(const ZZ& zz1, const ZZ& zz2) const
        {
            return zz1.note > zz2.note;
        } 
};

class CompareByName
{
    public:
        bool operator()(const ZZ& zz1, const ZZ& zz2) const
        {
            return zz1.nom > zz2.nom;
        } 
};

class Rand_a_b
{
    private:
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution;

    public:
    /**
     * L'utilisation de std::random_device() avec deux parenthèses () est nécessaire 
     * pour créer une instance de std::random_device et générer une valeur aléatoire à partir de cette instance.
    */
        Rand_a_b(int a, int b) : generator(63), distribution(a, b){}
        
        int operator()()
        {
            return distribution(generator);
        } 
};

class Fibonacci_n
{
    int a;
    int b;

    public:
        Fibonacci_n() : a(0), b(1){}

        int operator()(int n)
        {
            if (n == 0) return 0;
            if (n == 1) return 1;

            int res = 0;
            for (int i = 2; i <= n; ++i)
            {
                res = a + b;
                a = b;
                b = res;
            }
            return res;
        }
};


class SortFonc
{
    public:
        bool operator()(const std::string& str1, const std::string& str2)
        {
            return str1.substr(1) < str2.substr(1);
        }
};


class ToUpperCase
{
    public:
        // ne pas oublier les references pour que la modification soit effective
        void operator()(std::vector<std::string>& strings)
        {
            /*for(char& c : str)
            {
                c = std::toupper(c);
            }*/

            std::for_each(strings.begin(), strings.end(), [](std::string& str){
                std::for_each(str.begin(), str.end(), [](char& c){c = std::toupper(c); });
            });  
        }
};
#endif

   


