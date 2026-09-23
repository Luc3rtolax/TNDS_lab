#ifndef Solutore__
#define Solutore__


#include "Funzionebase.h"
#include <iostream>
using namespace std;

class Solutore {
    public: 
    Solutore();
    Solutore (double prec);

    virtual ~Solutore() {;};

    virtual double Cercazerireference (double xmin, double xmax, const Funzionebase& f, double prec=1E-6, unsigned int nmax=1000)=0;

    void SetPrecisione(double epsilon) { m_prec = epsilon; }
    double GetPrecisione() { return m_prec;}

    void SetNMaxiterations(unsigned int n ) { m_nmax = n ; }
    unsigned int GetNMaxiterations () { return m_nmax ; } ;

    unsigned int GetNiterations () { return m_niterations ; } ;


    protected:


    double m_a, m_b;              // estremi intervallo di ricerca
    double m_prec;                // precisione richiesta
    unsigned int m_nmax;          // massimo numero di iterazioni permesse 
    unsigned int m_niterations;   // numero di iterazioni effettuate

};

class Bisezione: public Solutore {
    public: 
    Bisezione() ;
    Bisezione (double prec);
    virtual ~Bisezione() {;};

    virtual double Cercazerireference( double xmin, double xmax, const Funzionebase& f, double prec=1E-6, unsigned int nmax=1000) override;
};





#endif