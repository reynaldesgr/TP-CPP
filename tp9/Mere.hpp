#ifndef MERE_HPP
#define MERE_HPP

template<class T>
class Mere
{
    protected:
        T a;
    public:
        Mere(T t):a(t) {}
        void f(){ std::cout << a << std::endl; }  

};

#endif // ! MERE_HPP

