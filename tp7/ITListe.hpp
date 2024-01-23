#ifndef ITListe_HPP
#define ITListe_HPP
#include "Liste.hpp"


class ITListe
{

    int    numELem;
    Cell * head;

    public:
        ITListe();
        ITListe(Cell *);
        ITListe begin();
        ITListe end();

        // Overloading
        ITListe& operator++();
        bool     operator!=(const ITListe&) const;
        int      operator* ()               const;
};
#endif // ITListe_HPP


