#include <iostream>



class Forme
{
    public:
        virtual void afficher()
        {
            std::cout << " Je suis une forme " << std::endl;
        } 
};


class Cercle : public Forme{

    public:
        void afficher() override
        {
            std::cout << " Je suis un cercle " << std::endl;     
        } 
};



void afficher1(Forme f) {
   f.afficher();
}

void afficher2(Forme &f) {
   f.afficher();
}

void afficher3(Forme * f) {
   f->afficher();
}

int main(int, char**) {
   Cercle cercle;
   
   afficher1(cercle);
   afficher2(cercle);
   afficher3(&cercle);
   
   return 0;
}
