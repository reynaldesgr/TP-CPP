#ifndef MACHINE_HPP
#define MACHINE_HPP


class Machine 
{
    std::string type;
    int autonomie;
    int itfixit;

    public:
        Machine(const std::string& t, int a, int i): type(t), autonomie(a), itfixit(i){}

        std::string getType     ()      const { return type; }
        int         getAutonomie()      const { return autonomie; }
        int         getIfixit   ()      const { return itfixit; }


        void        setType     (std::string inType)     { type = inType; }
        void        setAutonomie(int inAutonomie)        { autonomie = inAutonomie; }
        void        setItfixit  (int inItfixit)          { itfixit = inItfixit; } 
};


#endif // ! MACHINE_HPP

