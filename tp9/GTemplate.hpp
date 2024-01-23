#ifndef GTEMPLATE_HPP
#define GTEMPLATE_HPP

#include <iostream>

#include <vector>
#include <fstream>


template<typename T>
class Stats
{
    std::vector<T> data;
    T sum;
    double moy;
    double ecart;

    public:
        Stats():data(10), moy(.0){} 

        void push_back(const T& t){ data.push_back(t); } 

        void compute(){}

        void display(std::ostream& o = std::cout) const 
        {
            // ne pas oublier le typename pour preciser au compilateur que T est attendu comme un 'type'
            for (typename std::vector<T>::const_iterator iter = data.begin(); iter != data.end(); ++iter)
            {
                o << *iter <<  " ";
            } 
            o << std::endl;
        } 
};

#endif // ! GTEMPLATE_HPP

