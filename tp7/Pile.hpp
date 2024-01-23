#ifndef PILE_HPP
#define PILE_HPP


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

#endif // PILE_HPP



