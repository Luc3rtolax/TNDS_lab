#ifndef Funzione__
#define Funzione__

#include <iostream>
#include <cmath>
using namespace std;

class Funzionebase {
    public:

    virtual double Eval(double) const=0;
    virtual ~Funzionebase() {;};
    virtual int sign(double x) const =0;
};

class Parabola: public Funzionebase {
    public:
    Parabola() {m_a=0; m_b=0; m_c=1;}
    Parabola(double a, double b, double c) {m_a=a; m_b=b; m_c=c;}
    ~Parabola() {;};
    virtual double Eval(double x) const  {return m_a*x*x+m_b*x+m_c;}
    double operator () (double x) {return m_a*x*x+m_b*x+m_c;}
    void SetA(double a) { m_a = a; }
    double GetA() const {return m_a;} 
    void SetB(double b) { m_b = b; }
    double GetB() const {return m_b;} 
    void SetC(double c) { m_c = c; }
    double GetC() const {return m_c;} 

    double Getvertex() const { return -m_b / (2*m_a) ;} ;
    virtual int sign (double x) const;

    private:
    double m_a, m_b, m_c;
};

class Tangente: public Funzionebase {
    public: 
    Tangente() {;};
    ~Tangente() {;};
    virtual double Eval(double x) const {return sin(x)-x*cos(x); };
    virtual int sign (double x) const;
};

#endif