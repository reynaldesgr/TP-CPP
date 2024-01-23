#include <iostream>

#include "VecteurDynamique.hpp"



VecteurDynamique::VecteurDynamique(size_t inCapacity):data(nullptr), size(0), capacity(inCapacity)
{
    data = new double[inCapacity]; 
}


VecteurDynamique::VecteurDynamique(const VecteurDynamique& other):size(other.size), capacity(other.capacity)
{
    data = new double[capacity];
    std::memcpy(data, other.data, size * sizeof(double));
}


const size_t& VecteurDynamique::getCapacity() const
{
    return capacity;
}

const size_t& VecteurDynamique::getSize() const
{
    return size;
}


void VecteurDynamique::setData(const double* newData, size_t newSize) 
{
    if (newSize <= capacity) 
    {
        std::memcpy(data, newData, newSize * sizeof(double));
        size = newSize;
    } 
    else 
    {
        double * newDataArray = new double[newSize];
        std::memcpy(newDataArray, newData, newSize * sizeof(double));

        delete[] data;
        data = newDataArray;

        size     = newSize;
        capacity = newSize;
    }
}


const double * VecteurDynamique::getData() const
{
    return data;
}


double& VecteurDynamique::operator[](size_t index)
{
    if (index < capacity)
    {
        return data[index];         
    } 

    throw std::out_of_range("Invalid index.");
}


std::ostream& operator<<(std::ostream oss, const VecteurDynamique &c) 
{
    if (c.getData()) 
    {
        for (size_t i = 0; i < c.getSize(); i++)
        {
            oss << c.getData()[i]; 
        } 
    } 

    return oss;
}

VecteurDynamique operator+(const VecteurDynamique& a, const VecteurDynamique& b) {
    VecteurDynamique result(a.getSize() + b.getSize());

    result.setData(a.getData(), a.getSize());
    result.setData(b.getData(), b.getSize() + a.getSize());

    return result;
}

VecteurDynamique::~VecteurDynamique()
{
    delete [] data; 
}
