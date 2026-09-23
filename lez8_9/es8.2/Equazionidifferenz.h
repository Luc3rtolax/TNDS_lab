#ifndef __EquazioniDifferenziali_h__
#define __EquazioniDifferenziali_h__
#include <string>
#include "Vectoroperators.h"
#include <iomanip>

class Funzionevettbase {
    public:
    virtual vector<double> Eval(double t, const vector<double> &x) const=0;  
};

class Oscillatorearmonico: public Funzionevettbase {
    public:
  Oscillatorearmonico(double m) {m_omega0=m;};
  Oscillatorearmonico() {;};

    vector<double> Eval (double t, const vector<double> &a) const override;
    
  
    private:
    double m_omega0;
};

class Equazionedifferenzbase {
    public:
     virtual vector<double> Passo(double t, const vector<double>& x, double h, const Funzionevettbase &f) const=0;
};

class Eulero: public Equazionedifferenzbase {

    public:
    Eulero() {;};

     vector<double> Passo(double t, const vector<double>& x, double h, const Funzionevettbase &f) const override;
};

class RangeKutta: public Equazionedifferenzbase {
    public:
    RangeKutta() {;};

    vector<double> Passo(double t,const vector<double>& x, double h, const Funzionevettbase &f) const override;
};


string convert ( double h ) ;



#endif