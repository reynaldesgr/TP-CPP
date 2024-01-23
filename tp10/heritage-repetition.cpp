#include <iostream>

using namespace std;

class A {
 protected:
    int attr;
 public:
   A() { cout << "A ";}
  virtual ~A() { cout << "~A ";}
};

class B : virtual public A {
 public:
   B() { cout << "B "; }
  virtual ~B() { cout << "~B ";}
};

class C : virtual public A {
 public:
   C() { cout << "C ";}
  virtual ~C() { cout << "~C ";}
};

class D : public B, public C {
 public:
   D() { cout << "D ";}
  virtual ~D() { cout << "~D ";}
  int getAttr(){ return this->attr; } 
};

int main(int, char**) {
  D d;
  cout << "\n C'est Fini !\n ";
  cout << d.getAttr() << endl; 
  /**
   * si non 'virtual' :
   * request for member 'attr' is ambiguous 
  */
  return 0 ;
}
