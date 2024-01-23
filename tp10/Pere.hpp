#ifndef PERE_HPP
#define PERE_HPP


class Pere 
{
    static int counter = 0;
    int id;

    public:
        Pere(){ id = ++counter; } 
};
#endif // ! PERE_HPP

