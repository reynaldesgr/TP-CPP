#ifndef LISTE_HPP
#define LISTE_HPP

#include <ostream>

class Cell 
{

    public:
        int    val;
        Cell * suiv;

    public:
        Cell();
        Cell(int);
};



class Liste
{
    int numElem;
    Cell * deb;

    public:
        Liste();
        Liste(Liste&);
       ~Liste();

        const Cell * getDeb()           const;
        const int&   getNbElem()        const;

        bool         empty()            const;
        void         push_front(int);

        void         pop_front();
        void         pop_back ();

        const Cell&  front()            const;
        const Cell&  back ()            const;


        Liste&               operator= (const Liste&);

        std::ostream&        operator<<(std::ostream &o);


        /** Itérateurs **/
        class ItList {
            private:
                Cell* cell;

            public:
                // Default constructor
                ItList() : cell(nullptr) {}

                // Constructor with a Cell pointer parameter
                ItList(Cell* c) : cell(c) {}

                // Overload the dereference operator
                int operator*() const {
                    return cell->val;
                }

                // Overload the equality operator
                bool operator!=(const ItList& other) const {
                    return cell != other.cell;
                }

                // Overload the increment operator (prefix)
                ItList& operator++() {
                    if (cell) {
                        cell = cell->suiv;
                    }
                    return *this;
                }
        };
        // Method to get the iterator pointing to the beginning of the list
        ItList begin() {
            return ItList(deb);
        }

        // Method to get the iterator pointing to the end of the list
        ItList end() {
            return ItList(nullptr);
        }
};

#endif // LISTE_HPP