#include "Funzionebase.h"

float sign (double x) {
    if (x==0) {
        return 0;
    } else {
        if(x<0) {
            return -1;
        } else {
            return 1;
        }
    }
};

double Gauss:: Eval(double x) const {
    double sigmadue=pow(m_sigma,2);
    double a= sqrt(2*M_PI*sigmadue);
    double b=pow(x-m_mean, 2);
    double c=-(b/(2*sigmadue));
    a=1/a;
    return a*exp(c);
};

