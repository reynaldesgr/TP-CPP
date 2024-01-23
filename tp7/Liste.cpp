#include <iostream>
#include "Liste.hpp"


Cell::Cell()
{
    val  = 0;
    suiv = nullptr;
}

Cell::Cell(int inVal) 
{
    val = inVal;
    suiv = nullptr;
}

Liste::Liste()
{
    numElem = 0;
    deb     = nullptr;
}

Liste::Liste(Liste& other)
{
    numElem = 0;
    deb     = nullptr;

    const Cell* current = other.getDeb();

    while (current != nullptr) 
    {
        push_front(current->val);
        current = current->suiv;
    }

}


const Cell * Liste::getDeb() const
{
    return deb;
}

const int& Liste::getNbElem() const
{
    return numElem;
}

bool Liste::empty() const
{
    return (deb == nullptr ? true : false);
}


Liste::~Liste()
{
    while (deb != nullptr)
    {
        Cell * tmp = deb;
        deb        = deb->suiv;
        delete tmp;
    } 
}


void Liste::push_front(int v) 
{
    Cell * newDeb = new Cell(v); // pas besoin de gérer l'exception, new le fait pour nous

    newDeb->suiv   = deb;
    deb            = newDeb;
    numElem++;
}

const Cell& Liste::front() const
{
    if (deb == nullptr)
    {
        throw std::invalid_argument("head is null (list is empty)");    
    }
    return *deb;
}

const Cell& Liste::back() const
{
    if (deb == nullptr)
    {
        throw std::invalid_argument("head is null (list is empty)");
    } 

    Cell * ptCurrent = deb;

    while (ptCurrent->suiv != nullptr)
    {
        ptCurrent = ptCurrent->suiv;
    }

    return *ptCurrent;
}


void Liste::pop_front()
{
    if (deb == nullptr)
    {
        throw std::invalid_argument("head is null (list is empty)");
    } 

    Cell * head = deb;
    deb         = deb->suiv;
    numElem--;

    delete head;
}


void Liste::pop_back()
{
    if (deb == nullptr)
    {
        throw std::invalid_argument("head is null (list is empty)");
    } 

    Cell * ptCurrent = deb;
    Cell * prec      = nullptr;

    while (ptCurrent->suiv != nullptr)
    {
        prec      = ptCurrent;
        ptCurrent = ptCurrent->suiv;
    }

    prec->suiv = nullptr;
    numElem--;

    delete ptCurrent;
}


std::ostream& Liste::operator<<(std::ostream &o)
{
    Cell * current = deb;
    while (current != nullptr)
    {
        o << current->val << " ";
        current = current->suiv;
    } 
    o << std::endl;

    delete current;

    return o;
}



Liste& Liste::operator=(const Liste& other)
{
    if (this != &other)
    {
        while(!empty())
        {
            pop_front();
        } 

        const Cell * current = other.getDeb();

        while (current != nullptr)
        {
            push_front(current->val);
            current = current->suiv;
        }   
    }

    return *this;
}
