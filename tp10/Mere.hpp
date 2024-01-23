#ifndef MERE_HPP
#define MERE_HPP


class Mere
{
    static int counter;
    int id;

    public:
        Mere(){ id = ++counter; } 
}

#endif // ! MERE_HPP

