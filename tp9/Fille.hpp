#ifndef FILLE_HPP
#define FILLE_HPP

#include "Mere.hpp"

template<class T>
class Fille : public Mere<T>
{
    public:
        Fille(T t) : Mere<T>(t){}

        // rajout du this->
        void m()
        {
            this->a = this->a * this->a;
            this->f();
        }  
};

#endif // ! FILLE_HPP

