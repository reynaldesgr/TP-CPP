#ifndef __PILE_HPP__
#define __PILE_HPP__


class Pile
{
    int * tab;
    int   taille;
    int   capacite;

    public:
        Pile();
        Pile(int);
       ~Pile();

        const int& size() const;
        const int& top() const;  
        bool isEmpty() const;
        void pop();
        void push(const int&);
};

#endif // __PILE_HPP__



