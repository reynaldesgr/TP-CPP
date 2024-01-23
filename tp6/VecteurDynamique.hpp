#ifndef __VECTEUR_DYNAMIQUE_HPP__
#define __VECTEUR_DYNAMIQUE_HPP__

#include <iostream>
#include <cstring>


class VecteurDynamique 
{
    double * data;
    size_t   size;
    size_t   capacity;


    public:
        VecteurDynamique(size_t);
        VecteurDynamique(const VecteurDynamique&);

       ~VecteurDynamique();

      void setData(const double* newData, size_t newSize);

       const size_t&  getCapacity() const;
       const size_t&  getSize() const;
       const double * getData() const;
       void           push_back(double);

       double& operator[](size_t);

       VecteurDynamique&               operator= (const VecteurDynamique&);

      // car fonction
       friend std::ostream&            operator<<(std::ostream& o, const VecteurDynamique &c);
       friend VecteurDynamique         operator+(const VecteurDynamique &a, const VecteurDynamique &b);
};

#endif // __VECTEUR_DYNAMIQUE_HPP__



