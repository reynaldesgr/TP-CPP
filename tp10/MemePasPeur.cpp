#include <iostream>


class MemePasPeur
{
    int tab[4];
    public:
        MemePasPeur() 
        {
            tab[0] = 1; 
        }

        const int & val() const {
            return tab[0]; 
        }

        void modify()
        {
            tab[0] = 4;  
        } 
};


int main(int, char**)
{
    MemePasPeur * p = new MemePasPeur;

    int i = p->val();

    const int & j = p->val();

    std::cout << i << " " << j << std::endl; // 1 1 

    p->modify();

    std::cout << i << " " << j << std::endl; // 1 4 

    delete p;

    std::cout << i << " " << j << std::endl; // 1 1574555352 (erreur de contexte)

    return 0;
}

