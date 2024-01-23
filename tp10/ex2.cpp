#include <iostream>

using namespace std;

class Mere
{
    public:
        Mere(){ m(); }
        virtual void m(){ cout << "mm" << endl; }
        virtual ~Mere(){}      
};


class Fille : public Mere
{
    public: 
        Fille(){ m(); }
        virtual void m(){ cout << "mf" << endl; }  
        virtual ~Fille() {}   
};


int main(int, char**)
{
    //Fille * f = new Fille; // mm puis mf (construction de mere puis de fille)
    Mere * o = new Fille; // mm puis mf
    o->m(); // mf

    // ! fuite de mémoire
    delete o;
}
