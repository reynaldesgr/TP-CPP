#ifndef PILEG_HPP
#define PILEG_HPP

template <typename T>
class PileG
{
    T   * tab;
    int   taille;
    int   capacite;

    public:
        PileG();
        PileG(int);
       ~PileG();

        const int& size() const;
        const T& top() const;  
        bool isEmpty() const;
        void pop();
        void push(const T&);
};

template <typename T>
PileG<T>::PileG():tab(nullptr), taille(0), capacite(10)
{
    if (capacite <= 0)
    {
        throw std::invalid_argument("Invalid capacity.");
            
    } 
    tab = new T[capacite]; 
}

template <typename T>
PileG<T>::PileG(int inCapacite):tab(nullptr), taille(0), capacite(inCapacite)
{
    if (capacite <= 0)
    {
        throw std::invalid_argument("Invalid capacity.");
    } 
    tab = new T[capacite]; 
}

template <typename T>
const int& PileG<T>::size() const
{
    return taille;
}

template <typename T>
const T& PileG<T>::top() const 
{
    if (taille > 0)
    {
        return tab[taille - 1]; 
    }
    throw std::out_of_range("Stack is empty."); 
}

template <typename T>
bool PileG<T>::isEmpty() const 
{
    return (taille == 0);
}

template <typename T>
void PileG<T>::pop()
{
    if (taille == 0)
    {
        throw std::invalid_argument("Invalid size.");
    } 
    --taille;
}

template <typename T>
void PileG<T>::push(const T& el)
{
    tab[taille] = el;
    ++taille; 
}

template <typename T>
PileG<T>::~PileG()
{
    delete [] tab; 
}

#endif ! // PILEG_HPP

