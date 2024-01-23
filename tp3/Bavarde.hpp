#ifndef __BAVARDE_HPP__
#define __BAVARDE_HPP__

#include <iostream>

class Bavarde {
  static int counter;

  int num;

  public:
        Bavarde();
        Bavarde(int);
        
        void fonction(Bavarde b);
        void afficher(void);
        int get(void);

        ~Bavarde();
};



#endif // __BAVARDE_HPP__



