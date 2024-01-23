#ifndef __A_HPP__
#define __A_HPP__

class B;

class A 
{
    public:
        int i;
    
    public:
        void exec(int);
        void send(B * obj);
};

#endif // __A_HPP__