#include "Solutore.h"

Solutore:: Solutore() {
    m_a=-1;
    m_b=1;              // estremi intervallo di ricerca
    m_prec=0.01;                // precisione richiesta
    m_nmax=1;          // massimo numero di iterazioni permesse 
    m_niterations=0;   // numero di iterazioni effettuate
};

Solutore:: Solutore(double p) {
    m_a=-1;
    m_b=1;              // estremi intervallo di ricerca
    m_prec=p;                // precisione richiesta
    m_nmax=1;          // massimo numero di iterazioni permesse 
    m_niterations=1;   
};

Bisezione:: Bisezione() : Solutore() {;};
Bisezione:: Bisezione(double p): Solutore( p) {;};
double Bisezione:: Cercazerireference(double xmin, double xmax, const Funzionebase& f, double prec , unsigned int nmax ) {
    double dx=prec+1;
    unsigned int i=0;
    double x;
    while ((dx>prec)&&(i<nmax)) {
        
        
        double dx=xmax-xmin;
        x=xmin+ dx/2;
   
        
        if (f.sign(xmin)*f.sign(x)<0) {
            xmax=x;
        }
        if (f.sign(x)*f.sign(xmax)<0) {
            xmin=x;
        }
        i++;
    }
    return x;
};