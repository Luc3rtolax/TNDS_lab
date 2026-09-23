#ifndef Integrali__
#define Integrali__
#include "Funzionebase.h"
#include <iostream>
#include <cmath>
using namespace std;

class Integral {
    public:

    Integral(double a, double b) {
        checkInterval(a,b);
        m_nstep=0;
        m_h=0;
        m_sum=0;
        m_integral=0;
    };
    virtual double Integra(unsigned int nstep, const Funzionebase& f)=0;

    void checkInterval(double a, double b) {
        m_a=min(a,b);
        m_b=max(a,b);
        if (a>b) m_sign=-1;
        else m_sign= 1;
    }
    protected:
    unsigned int m_nstep;
    double m_a, m_b;
    double m_sum, m_integral, m_h;
    int m_sign;

};

class Midpoint: public Integral {
    public:
    Midpoint (double a, double b): Integral (a,b) {;};

    double Integra(unsigned int nstep, const Funzionebase& f);

};

class Simpson:  public Integral {
    public:
    Simpson(double a, double b): Integral (a,b) {;};

    double Integra(unsigned int nstep, const Funzionebase& f);
};


class Trapezi: public Integral {
    public:
    Trapezi(double a, double b): Integral (a,b) {;};

    double Integra(unsigned int nstep, const Funzionebase& f);
    double Integra(double prec,const Funzionebase& f);
    double IntegraM(double prec, const Funzionebase& f);
};

class Midright: public Integral {
    public:
    Midright (double a, double b): Integral (a,b) {;};

    double Integra(unsigned int nstep, const Funzionebase& f);

};





#endif