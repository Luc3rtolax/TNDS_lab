#ifndef RANDOMGEN___
#define RANDOMGEN___

#include <iostream>
#include <cmath>
#include <iomanip>
#include "Funzionebase.h"
#include <climits>
#include <cstdint>
using namespace std;

class Randomgen {
    public:

    Randomgen(uint32_t s){
        m_seed=s;
        m_a=1664525;
        m_c=1013904223;
    };

    double Rand();
    double Unif(double xmin, double xmax);
    double Exp(double lambda) ;  // distribuzione esponenziale con costante lambda
    double Gauss(double mean, double sigma);          // distribuzione gaussiana (Box-Muller)
    double Acceptreject(const Funzionebase& f, double xmax, double xmin, double max); // distribuzione gaussiana (Accept-Reject)


    private:
    uint32_t m_seed;
    uint32_t m_a;
    uint32_t m_c;
};







#endif