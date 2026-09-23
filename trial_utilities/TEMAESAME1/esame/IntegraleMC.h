#ifndef MC
#define MC

#include "Funzionebase.h"
#include "Randomgen.h"

#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;


class IntegraleMC
{
    public: 
    IntegraleMC(uint32_t seed):
    m_gen(seed)
    {
        m_errore=0;
        m_punti=0;
    }

    virtual double Integra (const Funzionebase& f, double inf, double sup, int punti, double max) = 0;

    double GetErrore() const {return m_errore;}
    int GetN() const{return m_punti;}

    protected:

    Randomgen m_gen;
    double m_errore;
    int m_punti;


};

class IntegratoreMedia : public IntegraleMC

{
    public: 

    IntegratoreMedia(uint32_t seed):IntegraleMC(seed) {;};

    virtual double Integra (const Funzionebase& f, double inf, double sup, int punti, double max) override;
};

class IntegratoreHitMiss : public IntegraleMC
{
    public: 

    IntegratoreHitMiss(uint32_t seed):IntegraleMC(seed) {;};

    virtual double Integra (const Funzionebase& f, double inf, double sup, int punti, double max) override;
};



#endif