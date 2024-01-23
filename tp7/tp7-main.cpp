#include <iostream>
#include "PileG.hpp"

template <typename T>
const T& maximum(const T& a, const T& b){
    return ((a > b) ? a : b);
}


int main()
{
    int a1 = 5;
    int b1 = 15;

    // Instanciation même type
    std::cout << "a1 = 5 (int) et b1 = 15 (int) -> max :  " << maximum(a1, b1) << std::endl;

    // Instanciation deux types différents (en forçant le type)

    // car sinon message d'erreur : 
    /**
     * tp7-main.cpp:4:10:  note: template argument deduction/substitution failed:
     * tp7-main.cpp:21:76: note: deduced conflicting types for parameter ‘const T’ (‘int’ and ‘double’)
    */

    int    a2 = 10;
    double b2 = 25.5;

    std::cout << "a2 (int) = 10 et b2 (double) = 25.5 -> max : " << maximum<double>(a2, b2) << std::endl;


    using PileEntiers = PileG<int>;

    PileEntiers p1;

    p1.push(10);
    p1.push(20);

    while (!p1.isEmpty())
    {
        std::cout << p1.top() << std::endl;
        p1.pop();
    }


    /** Liste **/
    return 0;
}
