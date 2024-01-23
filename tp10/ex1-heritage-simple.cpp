#include <iostream>

using namespace std;

class Mere 
{
    public:
        Mere() {
            cout << "Mere::Mere()" << endl;
            tab = new int[100];
        } 

        // Pour éviter une fuite de mémoire : rajouter le mot clé 'virtual'
        virtual ~Mere() {
            cout << "Mere::~Mere()" << endl;
            delete [] tab;
        }

    protected:
        int * tab;
};

class Fille : public Mere 
{
    public:
        Fille() {
            cout << "Fille:Fille()" << endl;
            tab = new double[100];
            Mere::tab[50] = 4;
        }
        ~Fille() 
        {
            cout << "Fille::~Fille()" << endl;
            delete [] tab;
        }

    protected:
        double * tab;
};

int main(int, char**) {
  Mere * m = new Fille();

  cout << "penser a valgrind" << endl;

  // appel seulement le destructeur de mere (pas celui de fille --> donc fuite de memoire)
  delete m; 
  return 0;
}
