#ifndef __particella 
#define __particella

#include <iostream>
#include <cmath>
using namespace std;

class Particella {
    public: 


    Particella() {m_m=0; m_c=0;};
    Particella(double m, double c) {m_m=m; m_c=c;};
    ~Particella() {};

    double GetMassa() const {return m_m;};
    double GetCarica() const {return m_c;};
    void print ()const;

    protected:
    double m_m;
    double m_c;
};

class Elettrone: public Particella {
    public:
    Elettrone();
    ~Elettrone() {};

    void print() const;
};

class Protone: public Particella {
    public:
    Protone();
    ~Protone() {};

    void print() const;
};

#endif