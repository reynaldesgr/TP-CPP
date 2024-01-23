#include "ITListe.hpp"

ITListe::ITListe()        : head(nullptr) {}
ITListe::ITListe(Cell* c) : head(c)       {} 

// Deference operator
int ITListe::operator*() const
{
    return head->val;
}

// Equality operator
bool ITListe::operator!=(const ITListe& other) const
{
    return head != other.head;
}


// Increment operator (prefix)
ITListe& ITListe::operator++()
{
    if (head)
    {
        head = head->suiv;
    }

    return *this; 
}


ITListe ITListe::begin()
{
    return ITListe(head);
}

ITListe ITListe::end()
{
    return ITListe(nullptr);
}







