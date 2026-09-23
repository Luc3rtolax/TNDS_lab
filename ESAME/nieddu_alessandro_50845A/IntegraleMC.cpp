#include "IntegraleMC.h"

double IntegratoreMedia::Integra (const Funzionebase& f, double inf, double sup, int punti, double max)
{
    double somma=0.;
    double somma2=0.;
    m_errore=0;

    m_punti=punti;
    
        for(int i=0; i<punti; i++)
        {
            double x=m_gen.Unif(inf,sup);
            somma+=f.Eval(x);
            somma2+=f.Eval(x)*f.Eval(x);
        }

        const double media = somma/punti;
        const double integrale = (sup-inf)*(somma/punti);
        
        //stima errore singola integrazione

        // const double varianza = (somma2-punti*media*media)/(punti-1);
        // m_errore = varianza*(sup-inf)*sqrt(punti);

        const double varianza = (somma2-punti*media*media)/(punti-1);
        m_errore = (sup-inf)*sqrt(varianza/punti);


    return integrale;
}

double IntegratoreHitMiss::Integra (const Funzionebase& f, double inf, double sup, int punti, double max)
{
    double somma=0.;
    m_errore=0;
    double x;
    double y;
    double integrale;

    for(int i=0; i<punti; i++)
    {
        x = m_gen.Unif(inf, sup);
        y = m_gen.Unif(0, max);
        if(y < f.Eval(x))
        {
            somma++;
        }
    }

    integrale = (sup-inf)*max*(somma/punti);

    return integrale;
}