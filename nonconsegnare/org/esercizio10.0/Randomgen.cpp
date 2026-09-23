#include "Randomgen.h"


double Randomgen:: Rand() {
    m_seed= (m_a*m_seed+m_c);
    return m_seed/pow(2,32);
    
};

double Randomgen:: Unif (double xmin, double xmax) {
    double m=Rand(); 
    return xmin+((xmax-xmin)*m);
};

double Randomgen:: Exp(double lambda) {
    double m=Rand();
    return m=-(1./lambda)*log(1-m);
};

double Randomgen:: Gauss(double mean, double sigma) {
    double s=Rand();
    double t=Rand();
    double x=sqrt(-2.*log(1.-s))*cos(2.*M_PI*t);
    return mean+x*sigma;
};

double Randomgen:: Acceptreject(const Funzionebase& f, double xmax, double xmin, double max) {
    double t=Rand();
    double x=xmin+(xmax-xmin)*t;
    double y=f.Eval(x)+1;
    while (y>f.Eval(x)) {
        double s=Rand();
        double n=Rand();
        x=xmin+(xmax-xmin)*s;
        y=max*n;
    }
    return x;
};

